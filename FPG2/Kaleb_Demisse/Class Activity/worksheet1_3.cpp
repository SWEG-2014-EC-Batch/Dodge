#include <iostream>
using namespace std;

void readList(float myList[], unsigned & maxNo);
float findMax(const float myList [] , unsigned maxNo);
float findMin(const float myList [] , unsigned maxNo);
float findRange(const float myList [] , unsigned maxNo);
float findmean(const float myList [] , unsigned maxNo);
float findmedian(const float myList [] , unsigned maxNo);
void display(const float myList [] , unsigned maxNo);

int main (){
    float marks[100];
    unsigned numMarks = 0;

    readList(marks, numMarks);

    display(marks, numMarks);
    return 0;
}
void readList(float myList[], unsigned & maxNo){
    cout << "Enter the number of marks: ";
    cin >> maxNo;

    cout << "Enter the marks: ";
    for (int i = 0; i < maxNo; i++) {
        cin >> myList[i];
    }

}
float findMax(const float myList [] , unsigned maxNo){
    float maxMark = myList[0];
    for (unsigned i = 1; i < maxNo; i++) {
        if (myList[i] > maxMark) {
            maxMark = myList[i];
        }
    }  
    return maxMark;
}
float findMin(const float myList [] , unsigned maxNo){
    float minMark = myList[0];
    for (unsigned i = 1; i < maxNo; i++) {
        if (myList[i] < minMark) {
            minMark = myList[i];
        }
    }
    return minMark;
}
float findRange(const float myList [] , unsigned maxNo){
    float maxMark = findMax(myList, maxNo);
    float minMark = findMin(myList, maxNo);
    return maxMark - minMark;
}
float findmean(const float myList [] , unsigned maxNo){
    float sum = 0.0;
    for (unsigned i = 0; i < maxNo; i++) {
        sum += myList[i];
    }
    return sum / maxNo;
}
float findmedian(const float myList [] , unsigned maxNo){
    float sortedList[100];
    float temp;
    for(int i = 0; i< maxNo; i++){
        sortedList[i]=myList[i];
    }
    for(int i = 0; i< maxNo; i++){
        for(int j = 0; j < maxNo; j++)
            if(sortedList[i] > sortedList[j]){
                temp = sortedList[i];
                sortedList[i] = sortedList[j];
                sortedList[j] = temp;
            }
    }
    if (maxNo % 2 == 0) {
        return ((sortedList[maxNo / 2 - 1] + sortedList[maxNo / 2]) / 2);
    } else {
        return (sortedList[maxNo / 2]);
    }
}
void display(const float myList [] , unsigned maxNo){
    cout << "Range: " << findRange(myList, maxNo) << endl;
    cout << "Mean: " << findmean(myList, maxNo) << endl;
    cout << "Median: " << findmedian(myList, maxNo) << endl;
}