#include<iostream>
using namespace std;
int main(){
    float netSlary,grossSalary,incometax,overtimerate,overTimePayment,workedHours,totalIncome,pension;
    int i, n;
    cout<<"for how many people do you want ?\n\t= ";
    cin >> n;
    for (i=0;i<n;i++)
    {
    cout <<"enter your gross salary\n\t= ";
    cin>>grossSalary;
    cout <<"enter your working hour\n\t= ";
    cin>>workedHours;
    if (workedHours>40){
        cout<<"enter over time payement per hour \n\t= ";
        cin>>overtimerate;
        overTimePayment=(workedHours-40)*overtimerate;}
    else {overTimePayment==0;}
    totalIncome=grossSalary+overTimePayment;
    if (totalIncome>=3500){
        incometax=totalIncome/100*30;}
    else if (totalIncome<3500 && totalIncome>=2000){
        incometax=totalIncome/100*25;}
    else if (totalIncome<2000 && totalIncome>=1200){
        incometax=totalIncome/100*20;}
    else if (totalIncome<1200 && totalIncome>=600){
        incometax=totalIncome/100*15;}
    else if (totalIncome<600 && totalIncome>=200){
        incometax=totalIncome/100*10;}
    else if (totalIncome<200){
        incometax=0;}
    pension=(grossSalary/100*7);
    netSlary=grossSalary-pension-incometax+overTimePayment;
    cout<<"you net salary is = " <<netSlary<<endl;
    if (workedHours<40){
        cout<<"But you are not illigable to take your wage because it is forbidden to work less than 40 hours per month!"<<endl;
    }
    }
    return 0;
}