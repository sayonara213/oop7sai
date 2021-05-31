#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

//  На основі контейнера list побудувати однозв’язні кільцеві 
//  списки цілих чисел та символьних рядків.
//  Виконати операції занесення елемента до 
//  списку, вилучення елемента зі списку, 
//  виведення елементів списку на екран, 
//  визначення кількості елементів списку.

template <typename T>
class MyList
{
private:
    list<T> List;
    auto Index(int _index);

public:
    MyList() { }


    T at(int index) { return (*this)[index]; }
    T operator[](int _index)
    {
        if (_index < 0)
        {
            auto it = Index(_index + List.size());
            return *it;
        }
        auto it = Index(_index);
        return *it;
    }

    void operator += (T elem)
    {
        List.push_back(elem);
    }

    MyList& operator += (const MyList<T>& obj)
    {
        for (auto it : obj.List)
        {
            List.push_back(it);
        }

        return *this;
    }

    void operator --(int obj)
    {
        if ((*this)() == 0)
        {
            cout << "List is empty!" << endl;
            return;
        }
        List.pop_back();
    }

    void operator --()
    {
        if ((*this)() == 0)
        {
            cout << "List is empty!" << endl;
            return;
        }
        List.pop_front();
    }

    friend ostream& operator << (ostream& os, MyList& obj)
    {

        for (auto it = obj.List.begin(); it != obj.List.end(); it++)
        {
            os << *it << endl;
        }
        return os;
    }

    int operator()() const {
        return List.size();
    }

    ifstream& operator >> (ifstream& fs)
    {
        T val;
        while (!fs.eof())
        {
            fs >> val;
            List.push_back(val);
        }

        return fs;
    }

    ofstream& operator << (ofstream& fs)
    {
        fs << '\n' << "Запиc у файл!" << '\n';
        for (auto it : List)
        {
            fs << it << endl;
        }

        return fs;
    }
};

int main()
{

    MyList<int> list1;
    MyList<int> list2;

    list1--;
    list1 += 420;
    list1 += 69;
    list1 += 228;
    list2 += 1440;
    --list2;
    list2 += 99;
    list2 += 99; 
    list2 += list1;
    list2 += list2[8];
    cout << "list2:" << endl << endl;
    cout << list2 << endl;
    cout << "Num of elem: " << list2() << endl;
    cout << "\n\n\n";

    MyList<string> list3;
    MyList<string> list4;

    list3 += "Bud";
    list3 += "=";
    list3 += "Perfect";
    list4 += "Pringles";
    list4 += "Disguisting";
    list4--;
    list4 += "+";
    list4 += list3;
    cout << "list4:" << endl << endl;
    cout << list4 << endl;
    cout << "Num of elem: " << list4() << endl;
    cout << "\n\n\n";

    string path("D:\\OOP\\read.txt");
    ifstream read;
    ofstream write;
    string p_write = "D:\\OOP\\write.txt";
    string p_read = "D:\\OOP\\read.txt";
    read.open(p_read);
    write.open(p_write, ios::ate | ios::in);
    cout << "\n\n\n";

    list2 << write;
    read.close();
    write.close();


}

template<typename T>
auto MyList<T>::Index(int _index)
{
    if (_index == 0)
    {
        return List.begin();
    }
    auto it = List.begin();
    int i = 0;
    do
    {
        if (it == List.end())
        {
            it = List.begin();
        }
        else
        {
            it++;
        }
        i++;
    } while (i < _index);

    if (it == List.end())
    {
        it = List.begin();
    }
    return it;
}





//
//
//#include <iostream>
//#include <list>
//#include <algorithm>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	list<string> MyList = { "danya loh","max loh","yura loh"};
//	
//	MyList.push_back("beninging");
//	MyList.push_front("pidaras");
//	MyList.sort();
//
//	for (auto it = MyList.begin(); it != MyList.end(); it++)
//	{
//		cout << *it << endl;
//	}
//
//}