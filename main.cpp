/*CSE-110-500 - Sean Eriksson - Lab 7
Arrays */

#include <iostream>  //input output
#include <fstream> //file handling
#include <cstdlib> //exit for file failure
#include <iomanip> //output formatting

using namespace std;

ifstream inputFile; //input file stream
ofstream outputFile("SeanEriksson.txt"); //output file stream

void open_files(); //opens the files and displays failures if they occur

void fill_array(double valuesArray[], int arraySize, int& slotsPopulated);  //files the array with data from the file

void bubble_sort(double valuesArray[], int slotsPopulated);  //sort the data from low to high

void output_data(double valuesArray[], int slotsPopulated); //show the output


int main()
{
    const int SIZE = 20;  //declare the size as 20
    double myArray[SIZE];  //create an array with the size of 20

    int slotsPopulated = 0;  //set slots populated to zero

    open_files();  //open the files
    fill_array(myArray, SIZE, slotsPopulated);  //call the fill array function
    bubble_sort(myArray, slotsPopulated);  //call the bubble sort function

    cout<<fixed<<setprecision(2);  //set the decimal point and set precision to two decimal places
    outputFile<<fixed<<setprecision(2);  //set the decimal point and set precision to two decimal places

    //output for the console
    cout<<"The number of sales amounts in the file is: "<<slotsPopulated<<endl;
    cout<<"The smallest sales amount is: $"<<myArray[0]<<endl;
    cout<<"The largest sales amount is: $"<<myArray[slotsPopulated - 1]<<endl;
    cout<<"The list of amounts sorted from lowest to highest:"<<endl;

    //output for the file
    outputFile<<"The number of sales amounts in the file is: "<<slotsPopulated<<endl;
    outputFile<<"The smallest sales amount is: $"<<myArray[0]<<endl;
    outputFile<<"The largest sales amount is: $"<<myArray[slotsPopulated - 1]<<endl;
    outputFile<<"The list of amounts sorted from lowest to highest:"<<endl;

    output_data(myArray, slotsPopulated);  //output the slots populated data

    return 0;
}

void open_files()  //open the files, display an error message if a problem occurs
{
    inputFile.open("salesAmounts.txt");  //open the file

    if (inputFile.fail())  //display error opening message
    {
        cout <<"Input file opening failed.\n";
        exit(1);
    }

    if(outputFile.fail())  //display error opening message
    {
        cout<<"Output file opening failed.\n";
        exit(1);
    }
}

void fill_array(double valuesArray[], int arraySize, int& slotsPopulated)  //fill the array and keep track of the slots populated

{
    int index = 0;  //declare an index for the array
    double nextValue;  //declare a variable to store the value when read

    inputFile>>nextValue; //read the value from the file first

    while ((nextValue>0) && (index<arraySize))
    {
        valuesArray[index] = nextValue;
        index++;
        inputFile>>nextValue;  //read the value last in the loop
    }

    slotsPopulated = index;  // store the number of slots used
}

void bubble_sort(double valuesArray[], int slotsPopulated)  //sort the array from low to high
{
    bool swap;  //create the swap flag
    double temp;  //create the temp slot

    do
    {
        swap = false;  //initially set to zero, a swap has not occurred
        for (int count = 0; count < (slotsPopulated - 1); count++)
        {
            if (valuesArray[count] > valuesArray[count + 1])  //check to see if the first item is greater than the second item
            {
                temp = valuesArray[count];  //set first item to temp
                valuesArray[count] = valuesArray[count + 1];  //move second item to first spot
                valuesArray[count + 1] = temp;  //move first item to second spot
                swap = true;  //swap occurred
            }
        }
    } while (swap);  //repeat if necessary
}



void output_data(double valuesArray[], int slotsPopulated)  //output data for the slots populated list
{
    int index = 0;  // declare an index for the array


    while (index<slotsPopulated)
    {
        cout<<"         $"<<valuesArray[index]<<endl;
        outputFile<<"        $"<<valuesArray[index]<<endl;
        index++;
    }
}
