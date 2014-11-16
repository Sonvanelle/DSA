#include <iostream>
#include "Stack.h"

using namespace std;

bool checkPrecedence(string& operatorInStack, string& newOperator){
	//Get Operator Precedence value for stack
	int StackOpValue = 0;
	if (operatorInStack == "(")
		StackOpValue = -1;
	if (operatorInStack == "+" || operatorInStack == "-")
		StackOpValue = 2;
	if (operatorInStack == "*" || operatorInStack == "/")
		StackOpValue = 4;
	if (operatorInStack == "^")
		StackOpValue = 6;

	//Get Operator Precedence value for new
	int newOpValue = 0;
	if (newOperator == "+" || newOperator == "-")
		newOpValue = 1;
	if (newOperator == "*" || newOperator == "/")
		newOpValue = 3;
	if (newOperator == "^")
		newOpValue = 5;

	//Compare and return if operatorInStack has precedence
	if (StackOpValue > newOpValue){
		return true;
	}
	return false;
}

string convertInfixToPostfix(string& expression, Stack& postFix){
	Stack OperatorStack;
	string tmpDgtStore = "";
	for (unsigned int i = 0; i < expression.length(); i++){
		ItemType item;
		//Check if expression is not a digit and there is an item in tmpDgtStore
		if (!isdigit(expression[i]) && tmpDgtStore.length() != 0){
			//Push into postfix and reset tmpDgtStore
			item = tmpDgtStore;
			postFix.push(item);
			tmpDgtStore = "";
		}
		//Check if expression is a space and ignore
		if (expression[i] == ' ') continue;

		//Check if expression is the operator "( or ^"
		if (expression[i] == '(' || expression[i] == '^'){
			//Push into Operator Stack
			item = expression[i];
			OperatorStack.push(item);
		}

		//Check if expression is an operator "+ - * /"
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'){
			//Pop operator from stack until stack empty or top has lower precedence than new operator
			ItemType opItem, newExpression;
			OperatorStack.getTop(opItem);
			newExpression = expression[i];
			while (!OperatorStack.isEmpty() && checkPrecedence(opItem, newExpression) && opItem != "("){
				OperatorStack.pop(item);
				postFix.push(item);
				OperatorStack.getTop(opItem);
					
			}
			//Push new expression into operator stack
			OperatorStack.push(newExpression);
		}

		//Check if expression is an operator that should make everything pop out from operator stack
		else if (expression[i] == ')'){
			//Pop and add everything into postFix stack until an openParthensis is popped or its empty
			ItemType opItem;
			OperatorStack.getTop(opItem);
			while (!OperatorStack.isEmpty()){
				if (opItem == "("){
					OperatorStack.pop();
					break;
				}
				else {
					OperatorStack.pop(item);
					postFix.push(item);
					OperatorStack.getTop(opItem);
				}
			}
		}
		
		else {
			//Just append into postFix if its not a digit
			if (isdigit(expression[i])){
				//Add into a tmp digit store
				tmpDgtStore += expression[i];
			}
			else {
				item = expression[i];
				postFix.push(item);
			}
		}
		/*DEBUG
		ItemType temp;
		OperatorStack.displayInOrderOfInsertion(temp);
		cout << "OperatorStack #" << i + 1 << ":" << temp << endl;
		postFix.displayInOrderOfInsertion(temp);
		cout << "Postfix #" << i + 1 << ":" << temp << endl;
		END OF DEBUG*/
	}

	ItemType tmp;
	//Add final values from tmpDgtStore is present
	if (tmpDgtStore.length() != 0){
		tmp = tmpDgtStore;
		postFix.push(tmp);
		tmpDgtStore = "";
	}
	//Add final operator stack into postfix
	while (!OperatorStack.isEmpty()){
		OperatorStack.pop(tmp);
		postFix.push(tmp);
	}
	//Return postfix string
	ItemType postFixString;
	postFix.displayInOrderOfInsertion(postFixString);
	return postFixString;
}

bool isBinaryOperator(ItemType& item){
	if (item == "+" || item == "-" || item == "/" || item == "*" || item == "^"){
		return true;
	}
	return false;
}

int doOperation(ItemType& firstExpr, ItemType& secondExpr, ItemType& Operator){
	//Convert to int
	int firstExprValue = stoi(firstExpr);
	int secondExprValue = stoi(secondExpr);
	if (Operator == "+"){
		return firstExprValue + secondExprValue;
	}
	if (Operator == "-"){
		return firstExprValue - secondExprValue;
	}
	if (Operator == "*"){
		return firstExprValue * secondExprValue;
	}
	if (Operator == "/"){
		return firstExprValue / secondExprValue;
	}
	if (Operator == "^"){
		return pow(firstExprValue, secondExprValue);
	}
}

string evalPostfix(Stack& postfix){
	//Reverse the postfix stack
	Stack reversedPostFix;
	ItemType resultValue;
	while (!postfix.isEmpty()){
		ItemType item;
		postfix.pop(item);
		reversedPostFix.push(item);
	}
	Stack eval;
	while (!reversedPostFix.isEmpty()){
		ItemType item;
		//Pop and transfer to eval if digit
		reversedPostFix.pop(item);
		string chkIfDigit = item;
		bool isDigit = true;
		for (int i = 0; i < chkIfDigit.length(); i++){
			if (!isdigit(chkIfDigit[i])){
				isDigit = false;
				break;
			}
		}

		if (isDigit){
			//It is a digit
			eval.push(item);
		}
		else {
			//It is an expression, go ahead and parse it
			//Check if operator
			if (!isBinaryOperator(item)){
				return "An error occured. An alphabet is found in the postfix expression and cannot be evaluated";
			}

			//Pop 2 from stack and evalulate them
			ItemType firstExpr, secondExpr;
			eval.pop(secondExpr);
			eval.pop(firstExpr);
			string resulttmp;
			resulttmp = to_string(doOperation(firstExpr, secondExpr, item));

			//Push it into the eval
			ItemType result;
			result = resulttmp;
			eval.push(result);
		}
	}
	//Get the evalulated number and return it
	eval.pop(resultValue);
	return resultValue;
}

int main(){
	Stack s;										//(3a)
	ItemType item;
	item = "3";
	s.push(item);									//(3b)
	item = "4";
	s.push(item);									//(3c)
	s.getTop(item);	
	cout << item << endl;							//(3d)
	s.displayInOrderOfInsertion();					//(3e)
	s.pop();										//(3f)
	s.displayInOrderOfInsertion();					//(3g)


	//Qn 3
	cout << "Enter Infix Expression: ";
	string infixExpress;
	getline(cin, infixExpress);

	Stack postFix;
	
	//Eg. 15 - (4*3) + (6/2) = 6
	string postfixExpress = convertInfixToPostfix(infixExpress, postFix);
	cout << "PostFix Expression: " << postfixExpress << endl;
	string evaluatedPostFix = evalPostfix(postFix);
	cout << "PostFix Evaluated: " << evaluatedPostFix << endl;
	return 0;
}

