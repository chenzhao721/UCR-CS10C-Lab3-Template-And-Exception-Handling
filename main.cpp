#include <vector>
#include <iostream>
#include <stdexcept>


using namespace std;
vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template <class T> unsigned min_index(const vector<T> &vals, unsigned index)
{
    unsigned min_index=index;
    for(int i=index;i<int(vals.size());i++)
        if(vals.at(i)<vals.at(min_index)) min_index=i;

    return min_index;
}

template <class T> void selection_sort(vector<T> &vals)
{
    unsigned m_index;
    for(int i=0;i<int(vals.size());i++)
    {
        m_index=min_index(vals,i);
        swap(vals.at(m_index),vals.at(i));

    }
}

template <class T> T getElement(vector<T> vals, int index)
{

    if(int(vals.size())<index) throw out_of_range("Invalid Index");

    return vals.at(index);
}
int main(){

    //Part A
    // vector<string> vec{"ccc","bbb","aaa","ddd","eee"};
    vector<double> vec{1.1,4.3,6.5,9.9,8.7,2.3,1.4};
    selection_sort<double>(vec);


    //Part B
    //  srand(time(0));
     vector<char> vals = createVector();
     cout<<vals.size()<<endl;
     char curChar;
     int numOfRuns = 10;
     int index;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;
         try{
             curChar = getElement<char>(vals,index);
             cout << "Element located at " << index << ": is " << curChar << endl;
         }
         catch(out_of_range &exception){cout<<exception.what()<<endl;}

    }
    return 0;
}