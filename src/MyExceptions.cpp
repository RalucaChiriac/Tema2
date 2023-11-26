#include "MyExceptions.h"
#include <string>
#include <vector>

using namespace std;

MyExceptions::MyExceptions(string exceptionType, string message, string value)
{
    this->exceptionType = exceptionType;
    this->message = message;
    this->value = value;
}

void MyExceptions::badTypeIntegerException(string input)
{
    if(!(input[0] == '-' || ('0' <= input[0] && input[0] <= '9')))
    {
        MyExceptions e("BAD DATA TYPE EXCEPTION", "Found STRING, required INTEGER", input);
        throw e;
    }

    for(int i = 1; i < input.size(); i++)
        if(!('0' <= input[i] && input[i] <= '9'))
        {
            MyExceptions e("BAD DATA TYPE EXCEPTION", "Found STRING, required INTEGER", input);
            throw e;
        }
}

void MyExceptions::vectorLengthException(int input)
{
    if(input < 0)
    {
        MyExceptions e("BAD LENGTH EXCEPTION", "Vector can't have negative length", to_string(input));
        throw e;
    }
}

void MyExceptions::negativeValueException(int input)
{
    if(input < 0)
    {
        MyExceptions e("UNACCEPTED VALUE EXCEPTION", "Expected positive value, found negative", to_string(input));
        throw e;
    }
}

void MyExceptions::acceptedInputException(string input, vector<string> expectedValues, int numOfExpectedValues)
{
    for(int i = 0; i < input.size(); i++)
        input[i] = toupper(input[i]);

    bool inExpectedValues = false;

    for(int i = 0; i < numOfExpectedValues; i++)
        for(int j = 0; j < expectedValues[i].size(); j++)
            expectedValues[i][j] = toupper(expectedValues[i][j]);

    for(int i = 0; i < numOfExpectedValues; i++)
    {
        bool sameWord = true;

        for(int j = 0; j < expectedValues[i].size(); j++)
            if(expectedValues[i][j] != input[j])
            {
                sameWord = false;
                break;
            }

        if(sameWord == true)
        {
            inExpectedValues = true;
            break;
        }
    }

    if(inExpectedValues == false)
    {
        string expectedValuesString = expectedValues[0];
        for(int i = 1; i < numOfExpectedValues; i++)
            expectedValuesString = expectedValuesString + "/" + expectedValues[i];

        MyExceptions e("UNACCEPTED VALUE EXCEPTION", "Expected [" + expectedValuesString + "]", input);
        throw e;
    }

}

void MyExceptions::outOfBoundsException(int position, int vectorLength,int startIndex)
{
    if(position < 0)
    {
        MyExceptions e("OUT OF BOUNDS EXCEPTION", "Vector does not have negative indexes", to_string(position));
        throw e;
    }
    else if(position <startIndex)
    {
        MyExceptions e("OUT OF BOUNDS EXCEPTION", "Introduced index is smaller the start Index of the vector", to_string(position));
        throw e;
    }
    else if(position > startIndex + vectorLength - 1)
    {
        MyExceptions e("OUT OF BOUNDS EXCEPTION", "Introduced index is greater than the length of the vector", to_string(position));
        throw e;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string MyExceptions::getException()
{
    return this->exceptionType + ": " + this->message + "; Your value: " + this->value;
}
