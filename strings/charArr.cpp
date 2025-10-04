#include<iostream>
using namespace std;

int main(){
    //character array
    char str[] = {'a', 'b', 'c'}; // each char takes 1 byte of size in memory
    char str2[] = {'d', 'e', 'f', '\0'};
    char str3[] = "any string"; // string literals

    //unlike integer arrays we can print character arrays without using loop, but by just using it's name
    cout << str << endl;
    cout << str2 << endl;

    int arr[] = {1,2,3,4};
    cout << *(arr) << endl; // this will print only the first value of the array, because the name of the array is nothing but pointer to address of its first value

    //string length
    cout << strlen(str)<< endl;
    cout << strlen(str2)<< endl;
    cout << str3 << endl;

   //jsut declaring string but not initilizing, will take input from user
    char name[50]; // here we will mandatorily have to define arr size
    cout << "Enter string : ";
    //cin >> name; // this will only take in the character before space, to take the whole sentence we will do the following
    cin.getline(name, 100, '#');
    cout << name << endl;
    

    return 0;
}