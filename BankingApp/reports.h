#pragma once
#ifndef REPORTS_H_
#define REPORTS_H_

//Create class
class Reports {

    //assign public accessible vars / functions for Reports class
public:
    //From Source
    Reports(double investment, double monthDeposit, double rate, int years);

    //From intreports
    void reportNoMonthlyDeposits();
    void reportMonthlyDeposits();
    virtual ~Reports();

    //assign private vars for Reports class
private:
   
    double initialDeposit;
    double monthlyDeposit;
    double interestRate;
    int numYears;

};
#endif