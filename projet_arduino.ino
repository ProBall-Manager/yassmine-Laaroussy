#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD I2C setup (0x27 is a common address, adjust if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin definitions
const int boutonPin = 2;
const int buzzerPin = 3;

// Time tracking
unsigned long precedentMillis = 0;
const long intervalle = 1000; // 1 second
const long intervalleAffichageScore = 15000; // 15 seconds

int minutes = 0;
int secondes = 0;

// Demo halftime and full time settings
int minutesMiTemps = 0;
int secondesMiTemps = 30;
int minutesTempsComplet = 1;
int secondesTempsComplet = 0;

bool miTempsAtteinte = false;
bool matchEnCours = true;

// Score tracking
int scoreEquipeA = 0;
int scoreEquipeB = 0;

unsigned long dernierAffichageScoreMillis = 0;

// Debounce for button
unsigned long dernierAppuiBouton = 0;
const unsigned long delaiDebounce = 200;

// Message display
const long dureeAffichageMessage = 2000;
unsigned long debutMessage = 0;
bool messageEnCours = false;

// Serial input
String inputString = "";
bool stringComplete = false;

void setup() {
  pinMode(boutonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.print("Debut Match!");
  delay(2000);
  lcd.clear();

  Serial.begin(9600);
  inputString.reserve(100);
}

void loop() {
  if (matchEnCours) {
    unsigned long tempsActuel = millis();

    // Update time every second
    if (tempsActuel - precedentMillis >= intervalle) {
      precedentMillis = tempsActuel;
      miseAJourTimer();
      afficherTemps();
    }

    // Show score every 15 seconds
    if (tempsActuel - dernierAffichageScoreMillis >= intervalleAffichageScore) {
      dernierAffichageScoreMillis = tempsActuel;
      afficherScore();
    }

    // Handle incoming serial input
    if (stringComplete) {
      traiterInputSerie();
      inputString = "";
      stringComplete = false;
    }
  }

  // Resume match after halftime
  if (miTempsAtteinte) {
    if (digitalRead(boutonPin) == LOW && (millis() - dernierAppuiBouton > delaiDebounce)) {
      dernierAppuiBouton = millis();
      miTempsAtteinte = false;
      matchEnCours = true;
      lcd.clear();
      afficherMessage("2e Mi-temps!");
      delay(2000);
      lcd.clear();
    }
  }
}

void miseAJourTimer() {
  secondes++;
  if (secondes >= 60) {
    secondes = 0;
    minutes++;
  }

  if (minutes == minutesMiTemps && secondes == secondesMiTemps && !miTempsAtteinte) {
    miTempsAtteinte = true;
    matchEnCours = false;
    digitalWrite(buzzerPin, HIGH);
    delay(2000);
    digitalWrite(buzzerPin, LOW);
    afficherMessage("Mi-temps!");
  }

  if (minutes == minutesTempsComplet && secondes == secondesTempsComplet) {
    matchEnCours = false;
    digitalWrite(buzzerPin, HIGH);
    delay(2000);
    digitalWrite(buzzerPin, LOW);
    afficherMessage("Match termine!");
  }
}

void afficherTemps() {
  if (messageEnCours && (millis() - debutMessage < dureeAffichageMessage)) return;
  messageEnCours = false;

  lcd.setCursor(0, 0);
  lcd.print("Temps: ");
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (secondes < 10) lcd.print("0");
  lcd.print(secondes);
}

void afficherScore() {
  lcd.setCursor(0, 1);
  lcd.print("Score ");
  lcd.print(scoreEquipeA);
  lcd.print("-");
  lcd.print(scoreEquipeB);
}

void sauvegarderDansBase() {
  Serial.print("INSERT INTO Match (time, scoreA, scoreB) VALUES ('");
  if (minutes < 10) Serial.print("0");
  Serial.print(minutes);
  Serial.print(":");
  if (secondes < 10) Serial.print("0");
  Serial.print(secondes);
  Serial.print("', ");
  Serial.print(scoreEquipeA);
  Serial.print(", ");
  Serial.print(scoreEquipeB);
  Serial.println(");");
}

void afficherMessage(const char* message) {
  lcd.clear();
  lcd.print(message);
  messageEnCours = true;
  debutMessage = millis();
}

void traiterInputSerie() {
  int indexVirgule = inputString.indexOf(',');
  if (indexVirgule != -1) {
    int newScoreA = inputString.substring(0, indexVirgule).toInt();
    int newScoreB = inputString.substring(indexVirgule + 1).toInt();

    if (newScoreA != scoreEquipeA || newScoreB != scoreEquipeB) {
      scoreEquipeA = newScoreA;
      scoreEquipeB = newScoreB;
      afficherScore();
      sauvegarderDansBase();
    }
  }
}

// Automatically called by Arduino when serial data arrives
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    } else if (isPrintable(inChar)) {
      inputString += inChar;
    }
  }
}
