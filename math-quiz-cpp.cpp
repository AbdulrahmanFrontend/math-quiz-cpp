#include <iostream>
using namespace std;
enum Question_Level { Easy = 1, Mid, Hard, Mix };
enum Operation_Type { Add = 1, Subtract, Multiply, Divide, Mixture };
float Read_Num(string message) {
  float num;
  cout << message;
  cin >> num;
  return num;
}
float Random_Num(short from, short to) {
  return rand() % (to - from + 1) + from;
}
Question_Level Read_Question_Level() {
  short question_level;
  cout << "\n*********************\n";
  cout << "The Numbers of levels:\n[1] Easy.\n[2] Mid.\n[3] Hard.\n[4] Mix.\n";
  cout << "************************************************************\n";
  do {
    question_level =
        Read_Num("Please, enter the number of the level you want to answer: ");
    if (!(question_level == 1 || question_level == 2 || question_level == 3 ||
          question_level == 4))
      cout << "The number you entered is wrong.\n";
    cout << "************************************************************\n";
  } while (!(question_level == 1 || question_level == 2 ||
             question_level == 3 || question_level == 4));
  return Question_Level(question_level);
}
string Name_Of_Question_Level(Question_Level question_level) {
  string name_of_question_level[4] = {"Easy", "Mid", "Hard", "Mix"};
  return name_of_question_level[Question_Level(question_level) - 1];
}
Operation_Type Read_Operation_Type() {
  short operation_type;
  cout << "************************************************************\n";
  cout << "The Numbers of operations:\n[1] for \'+\'.\n[2] for \'-\'.\n[3] for "
          "\'*\'.\n[4] for \'/\'.\n[5] Mix.\n";
  cout << "******************************************************\n";
  do {
    operation_type =
        Read_Num("Please, enter the number of the operation you want: ");
    if (!(operation_type == 1 || operation_type == 2 || operation_type == 3 ||
          operation_type == 4 || operation_type == 5))
      cout << "The number you entered is wrong.\n";
    cout << "******************************************************\n";
  } while (!(operation_type == 1 || operation_type == 2 ||
             operation_type == 3 || operation_type == 4 ||
             operation_type == 5));
  return Operation_Type(operation_type);
}
string Symbol_Of_Operation_Type(Operation_Type operation_type) {
  string symbol_of_operation_type[5] = {"+", "-", "*", "/", "Mix"};
  return symbol_of_operation_type[short(operation_type) - 1];
}
void Specify_Nums(float &num1, float &num2, Question_Level question_level) {
  switch (question_level) {
  case Question_Level::Easy:
    num1 = Random_Num(1, 9);
    num2 = Random_Num(1, 9);
    break;
  case Question_Level::Mid:
    num1 = Random_Num(10, 99);
    num2 = Random_Num(10, 99);
    break;
  case Question_Level::Hard:
    num1 = Random_Num(100, 999);
    num2 = Random_Num(100, 999);
    break;
  case Question_Level::Mix:
    num1 = Random_Num(1, 999);
    num2 = Random_Num(1, 999);
  }
}
float True_Result(float num1, float num2, Operation_Type &operation_type) {
  switch (operation_type) {
  case Operation_Type::Add:
    return num1 + num2;
  case Operation_Type::Subtract:
    return num1 - num2;
  case Operation_Type::Multiply:
    return num1 * num2;
  case Operation_Type::Divide:
    return num1 / num2;
  case Operation_Type::Mixture:
    operation_type = Operation_Type(Random_Num(1, 4));
    switch (operation_type) {
    case Operation_Type::Add:
      return num1 + num2;
    case Operation_Type::Subtract:
      return num1 - num2;
    case Operation_Type::Multiply:
      return num1 * num2;
    case Operation_Type::Divide:
      return num1 / num2;
    }
  }
}
bool Is_Result_True(float true_result, float user_answer) {
  return true_result == user_answer;
}
void Check_Result(float true_result, float user_result, float &true_answers,
                  float &false_answers) {
  if (Is_Result_True(true_result, user_result)) {
    cout << "Right Answer: -).\n";
    true_answers++;
  } else {
    cout << "Wrong Answer: -(.\n";
    cout << "The right answer is: " << true_result << ".\n";
    false_answers++;
  }
}
bool Check_Is_Pass(float true_answers, float false_answers) {
  return true_answers >= false_answers;
}
void Print_Is_Pass(float true_answers, float false_answers) {
  if (Check_Is_Pass(true_answers, false_answers)) {
    cout << "Final Result is Pass: -).\n";
  } else {
    cout << "\a";
    cout << "Final Result is Fail: -(.\n";
  }
}
void Final_Result(float num_question, Question_Level question_level,
                  Operation_Type operation_type, float true_answers,
                  float false_answers) {
  cout << "\n__________________________________________________________________"
          "______________\n";
  Print_Is_Pass(true_answers, false_answers);
  cout << "____________________________________________________________________"
          "____________\n";
  cout << "Number of questions: " << num_question << ".\n";
  cout << "Question level: " << Name_Of_Question_Level(question_level) << ".\n";
  cout << "Operation type: " << Symbol_Of_Operation_Type(operation_type)
       << ".\n";
  cout << "Number of right answers: " << true_answers << ".\n";
  cout << "Number of wrong answers: " << false_answers << ".\n";
  cout << "--------------------------------------------------------------------"
          "------------\n";
}
void Test() {
  short num_questions =
      Read_Num("Please, enter the number of the question you want to answer: ");
  Question_Level question_level = Read_Question_Level();
  Operation_Type operation_type = Read_Operation_Type();
  Operation_Type op_type = operation_type;
  float true_result, user_result, num1, num2;
  float true_answers = 0, false_answers = 0;
  cout << "\n======================================================";
  for (short i = 1; i <= num_questions; i++) {
    Specify_Nums(num1, num2, question_level);
    if (i > 1 && op_type == Operation_Type::Mixture)
      operation_type = op_type;
    true_result = True_Result(num1, num2, operation_type);
    cout << "\n*****************";
    cout << "\nQuestion [" << i << "/" << num_questions << "]:\n";
    cout << " " << num1 << "\n";
    cout << " " << num2;
    cout << " " << Symbol_Of_Operation_Type(operation_type) << "\n";
    cout << "--------\n";
    user_result = Read_Num(" ");
    cout << "------------------------------\n";
    Check_Result(true_result, user_result, true_answers, false_answers);
    cout << "------------------------------\n";
  }
  Final_Result(num_questions, question_level, op_type, true_answers,
               false_answers);
}
void Start_Test() {
  char retest;
  do {
    Test();
    do {
      cout << "Please, do you want to test again (y/n)? ";
      cin >> retest;
    } while (!(retest == 'y' || retest == 'n'));
    if (retest == 'y') {
      system("clear");
    }
  } while (retest == 'y');
}
int main() {
  srand((unsigned)time(NULL));
  Start_Test();
  return 0;
}