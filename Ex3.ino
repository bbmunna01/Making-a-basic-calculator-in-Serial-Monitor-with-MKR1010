float num1, num2, result;
char op;
String input;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("=== Arduino MKR1010 Float Calculator ===");
  Serial.println("Enter calculation (e.g. 8.5 + 3.2):");
}

void loop() {
  if (Serial.available()) {
    input = Serial.readStringUntil('\n');

    int space1 = input.indexOf(' ');
    int space2 = input.lastIndexOf(' ');

    if (space1 != -1 && space2 != -1 && space1 != space2) {
      String num1Str = input.substring(0, space1);
      String opStr   = input.substring(space1 + 1, space1 + 2);
      String num2Str = input.substring(space2 + 1);

      num1 = num1Str.toFloat();
      op   = opStr.charAt(0);
      num2 = num2Str.toFloat();

      bool valid = true;
      switch (op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/':
          if (num2 != 0) result = num1 / num2;
          else {
            Serial.println("Error: Division by zero!");
            valid = false;
          }
          break;
        default:
          Serial.println("Invalid operator! Use +, -, *, /");
          valid = false;
      }

      // Print result
      if (valid) {
        Serial.print("Result: ");
        Serial.println(result, 2); // print with 2 decimal places
      }
    } else {
      Serial.println("Invalid input format! Use: number operator number");
    }

    // Ask again
    Serial.println();
    Serial.println("Enter next calculation:");
  }
}