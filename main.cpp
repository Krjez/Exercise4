#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
void question1();
void question2();
void question3();
void question4();
void question7();
void question8();
void question9();
void question10();
void load(vector<int> &integers);
void display(const vector<int> &integers);

int main()
{
    cout << "Type in the number of desired function:" << endl;
    int num;
    cin >> num;

    switch(num)
    {
        case 1:
            question1();
            break;
        case 2:
            question2();
            break;
        case 3:
            question3();
            break;
        case 4:
            question4();
            break;
        case 7:
            question7();
            break;
        case 8:
            question8();
            break;
        case 9:
            question9();
            break;
        case 10:
            question10();
            break;
        default:
            cout << "Invalid choice" << endl << endl;
            break;
    }
}

void load(vector<int> &integers)
{
    ifstream file("../integers.txt");
    if(file)
    {
        int num;
        while(!file.eof())
        {
            file >> num;
            integers.push_back(num);
        }
        file.close();
    }
    else
    {
        cout << "Error while opening file." << endl;
    }
}

void display(const vector<int> &integers)
{
    cout << "[ ";
    for(int integer : integers)
    {
        cout << integer << ", ";
    }
    cout << "]" << endl;
}

void display(const vector<string> &strings)
{
    cout << "My Strings: [";
    for(const string &a : strings)
    {
        cout << a << ", ";
    }
    cout << "]" << endl;
}

int areSameUntil(const vector<int> &vec1, const vector<int> &vec2)
{
    int same = -1;
    int min = vec1.size() < vec2.size() ? vec1.size() : vec2.size();

    for(int i = 0; i < min; i++)
    {
         if(vec1[i] == vec2[i])
         {
             same++;
         }
         else
         {
             break;
         }
    }
    return same;
}

bool areSameReverse(const vector<int> &vec1, const vector<int> &vec2)
{
    int size = vec1.size();
    if(size != vec2.size())
    {
        return false;
    }

    for(int i = 0; i < size; i++)
    {
        if(vec1[i] != vec2[size-i])
        {
            return false;
        }
    }
    return true;
}

bool areSameReverseIters(const vector<int> &vec1, const vector<int> &vec2)
{
    vector<int>::const_iterator iterA = vec1.cbegin();
    vector<int>::const_reverse_iterator iterB = vec2.crbegin();

    while(iterA != vec1.cend() &&iterB != vec2.crend())
    {
        if(*iterA != *iterB)
        {
            return false;
        }
        iterA++;
        iterB++;
    }
    return iterA == vec1.cend() && iterB == vec2.crend();
}

void interleave(const vector<int> &vec1, const vector<int> &vec2, vector<int> &vec3)
{
    auto iterA = vec1.cbegin();
    auto iterB = vec2.cbegin();

    while(iterA != vec1.cend() || iterB != vec2.cend())
    {
        if(iterA != vec1.cend())
        {
            vec3.push_back(*iterA);
            iterA++;
        }
        if(iterB != vec2.cend())
        {
            vec3.push_back(*iterB);
            iterB++;
        }
    }
}

void question1()
{
    vector<int> integers;
    load(integers);


    cout << "Enter number to find" << endl;
    int key;
    cin >> key;
    bool found = false;
    for(int i = 0; i < integers.size(); i++)
    {
        if(integers[i] == key)
        {
            found = true;
            cout << key << " found at position: " << i << endl;
            //break;
        }
    }
    if(!found)
    {
        cout << "Not found the integer in the list" << endl;
    }
}

void question2()
{
    list<int> integers;

    ifstream file("../integers.txt");
    if(file)
    {
        int num;
        while(!file.eof())
        {
            file >> num;
            integers.push_back(num);
        }
        cout << "[ ";
        for(auto iter = integers.begin();
        iter != integers.end(); iter++)
        {
            cout << *iter << ", ";
        }
        cout << "]" << endl;

        file.close();
    }

    cout << "Enter number to find" << endl;
    int key;
    cin >> key;
    bool found = false;
    int pos = 0;
    for(int i : integers)
    {
        if(i == key)
        {
            found = true;
            cout << key << " found at position: " << pos << endl;
        }
        pos++;
    }
    if(!found)
    {
        cout << "Not found the integer in the list" << endl;
    }

}

void question3()
{
    vector<int> integers;
    load(integers);

    display(integers);

    sort(integers.begin(), integers.end());
    display(integers);

    sort(integers.rbegin(),integers.rend());
    display(integers);

    auto func1 = [](int x, int y) {return x < y;};
    sort(integers.begin(), integers.end(), func1);
    display(integers);

    auto func2 = [](int x, int y) {return x > y;};
    sort(integers.begin(), integers.end(), func2);
    display(integers);
}

void question4()
{
    vector<string> strings {"Well", "That", "Went", "Swimmingly", "Didn't", "It", "As"};
    for(string &a : strings)
    {
        cout << a << ", ";
    }
    cout << endl;

    auto strfunc = [](const string &a, const string &b){
        if(a.size() == b.size())
        {
            return a < b;
        }
        return b.size() > a.size();};
    sort(strings.begin(), strings.end(), strfunc);

    display(strings);
}

void question7()
{
    vector<string> monthVector {"Jan", "Apr", "May", "Sept", "Nov", "Dec"};
    vector<string>::iterator iter = monthVector.begin()+4;
    iter = monthVector.insert(iter,"Oct")-1;
    iter = monthVector.insert(iter,"Aug");
    iter = monthVector.insert(iter,"July");
    iter = monthVector.insert(iter,"June")-2;
    iter = monthVector.insert(iter, "Mar");
    iter = monthVector.insert(iter, "Feb");

    display(monthVector);
}

void question8()
{

    vector<int> v1 {5,9,1,3,5};
    vector<int> v2 {5,9,5,7,1};
    vector<int> v3 {5,2,3,3,5};
    vector<int> v4 {9,2,3,3,5};

    cout << "Should return 1: " << areSameUntil(v1, v2) << endl;
    cout << "Should return 0: " << areSameUntil(v2, v3) << endl;
    cout << "Should return 0: " << areSameUntil(v1, v3) << endl;
    cout << "Should return -1: " << areSameUntil(v1, v4) << endl;

}

void question9()
{

    vector<int> v1 {5,9,1};
    vector<int> v2 {3,6,3};
    vector<int> v3 {1,9,5};

    cout << "Should return false: ";
    if(areSameReverseIters(v1, v2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    cout << "Should return true: ";
    if(areSameReverseIters(v1, v3))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    cout << "Should return false: ";
    if(areSameReverseIters(v2, v3))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}

void question10()
{
    vector<int> v1{5,9,1};
    vector<int> v2{3,6,3};
    vector<int> v3{2,2,2,2};
    vector<int> v4;

    interleave(v1, v2, v4);
    display(v4);

    interleave(v2, v3, v4);
    display(v4);
}

//use struct for the car
void question11()
{

}