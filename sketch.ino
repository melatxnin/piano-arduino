/*
  PIANO

  Controls:
  Press a button to play the corresponding note.

  Ideas:
  Ode to Joy (Beethoven):
  E E F G G F E D C C D E E D D

  Brother John:
  C D E C C D E C E F G E F G

  Mary Had a Little Lamb:
  E D C D E E E D D D E G G
  
  Twinkle Twinkle Little Star:
  C C G G A A G F F E E D D C

  Author:
  Nicolas GOSSARD
*/

// settings
constexpr int noteNumber = 12;
constexpr int noteFrequencies[noteNumber] =
{
  262, // C
  277, // C#
  294, // D
  311, // D#
  330, // E
  349, // F
  370, // F#
  392, // G
  415, // G#
  440, // A
  466, // A#
  494  // B
};

// pins
constexpr int buzzerPin = A0;
constexpr int buttonPins[noteNumber] =
{
  13, // C
  12, // C#
  11, // D
  10, // D#
  9,  // E
  8,  // F
  7,  // F#
  6,  // G
  5,  // G#
  4,  // A
  3,  // A#
  2   // B
};

// state
int currentNoteIndex = -1;

void setup()
{
  pinMode(buzzerPin, OUTPUT);

  for (int i = 0; i < noteNumber; i++)
  {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop()
{
  int firstPressedIndex = -1;

  for (int i = 0; i < noteNumber; i++)
  {
    if (digitalRead(buttonPins[i]) == LOW)
    {
      firstPressedIndex = i;
      break;
    }
  }

  if (firstPressedIndex == -1)
  {
    if (currentNoteIndex != -1)
    {
      noTone(buzzerPin);
      currentNoteIndex = -1;
    }

    delay(5);
    return;
  }

  if (firstPressedIndex != currentNoteIndex)
  {
    tone(buzzerPin, noteFrequencies[firstPressedIndex]);
    currentNoteIndex = firstPressedIndex;
  }

  delay(5);
}
