/* Title: Payroll Management System (Pay Sys)
Group members:  Alfred Loo Wee How
                Gan Teck Beng
                Lau Jia Hui
                Yeap Yann Ling
Date: 10/05/2016 (latest edition) */
/*To compile:
1. g++ -std=c++11 -c Pay-Sys.cpp -o Pay-Sys.o
2. g++ -o Pay-Sys.exe Pay-Sys.o
To run:
1. .\Pay-Sys
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void start()
{
    cout << "\t\tWelcome to Pay Sys" << endl << endl << endl;
    cout << "This system will be used to calculate employee's net salary." << endl;
    cout << "Guide to use: " << endl;
    cout << "\t1. Enter employee information." << endl;
    cout << "\t2. Enter basic salary." << endl;
    cout << "\t3. Enter overtime & allowances." << endl;
    cout << "\t4. Enter EPF, SOCSO & Income Tax." << endl;
    cout << "\t5. Net salary will be printed on screen." << endl;

    cout << "\n\n-----------------------------------------------------------" << endl;
}

int main ()
{
    //Introduction part, c

    string employee_name, employee_position, employee_id;
    float basic_salary, epf, socso, tax, deduction, gross_salary, net_salary, annual_tax, income_to_charge;
    int working_hour, ot_type, allowance_type, epf_rate;
    char response;
    int n_overtime_hour = 0;
    int r_overtime_hour = 0;
    int p_overtime_hour = 0;
    float total_otpay = 0;
    float hr_allowance = 0;
    float tr_allowance = 0;
    float med_allowance = 0;
    float ent_allowance = 0;
    float total_allowance = 0;


    start();
    //Enter employee information
    cout << "\nEmployee information " << endl;
    cout << "----------------------" << endl << endl;
    cout << "Enter Employee Name: ";
    getline(cin, employee_name);
    cout << endl;

    cout << "Enter Employee ID: ";
    getline(cin,employee_id);
    cout << endl;

    cout << "Enter Employee Position: ";
    getline(cin,employee_position);
    cout << endl;

    cout << "\n\n-----------------------------------------------------------" << endl;

    //Input salary and calculate gross pay
    cout << "\nSalary Entry" << endl;
    cout << "--------------" << endl << endl;
    cout << "Enter Basic Salary(MYR): ";
    cin >> basic_salary;

    cout << "Enter Total Working Hours per month(excluding OT): ";
    cin >> working_hour;
    cout << endl;

    cout << "\tEmployee Basic Salary: RM " << fixed << setprecision(2) << basic_salary << endl << endl;

    //Input OT with different type and rate
    cout << "\nOvertime" << endl;
    cout << "--------" << endl << endl;
    do
    {
        cout << "Is there any overtime for this employee? (y/n): ";
        cin >> response;
    }
    while ((response != 'y') && (response != 'Y') && (response != 'n') && (response != 'N'));


    if ((response == 'y') || (response == 'Y'))
    {
        cout << "\n\tThere are 3 types of Overtime." << endl;
        cout << "\t\t1. Normal OT (OT during normal working day)." << endl;
        cout << "\t\t2. Rest Day OT (OT during Saturday or Sunday)." << endl;
        cout << "\t\t3. Public Holiday OT (OT during public holiday)." << endl;
        cout << "\t\t**Tips: Re-enter the type (1-3) to change the number of hours \n\t\tinput before." << endl << endl;

        do
        {
            cout << "\tEnter the type of OT (1-3) or Enter 0 to skip: ";
            cin >> ot_type;
        }
        while ((ot_type != 1) && (ot_type != 2) && (ot_type != 3) && (ot_type != 0));

        while (ot_type != 0)
        {
            if (ot_type == 1)
            {
                cout << "\tEnter Normal Overtime Hours: ";
                cin >> n_overtime_hour;
                cout << endl;
            }

            if (ot_type == 2)
            {
                cout << "\tEnter Rest Day Overtime Hours: ";
                cin >> r_overtime_hour;
                cout << endl;
            }

            if (ot_type == 3)
            {
                cout << "\tEnter Public Holiday Overtime Hours: ";
                cin >> p_overtime_hour;
                cout << endl;
            }

            cout << "\tEnter the type of OT (1-3)or Enter 0 to skip: ";
            cin >> ot_type;

        } ;

        //Calculate Total OT Pay
        total_otpay =  ((basic_salary/working_hour) * 1.5 * n_overtime_hour) + ((basic_salary/working_hour) * 2 * r_overtime_hour) + ((basic_salary/working_hour) * 3 * p_overtime_hour);

        cout << "\n\tEmployee Normal Working Hour: " << working_hour << endl;
        cout << "\tEmployee Normal Overtime Hour: " << n_overtime_hour << endl;
        cout << "\tEmployee Rest Day Overtime Hour: " << r_overtime_hour << endl;
        cout << "\tEmployee Public Holiday Overtime Hour: " << p_overtime_hour << endl << endl;
        cout << "\tEmployee Total OT Pay: RM " << fixed << setprecision(2) << total_otpay << endl << endl;
    }

    //Input allowances
    cout << "\nAllowance" << endl;
    cout << "---------" << endl << endl;
    do
    {
        cout << "Is there any allowance for this employee? (y/n): ";
        cin >> response;
    }
    while ((response != 'y') && (response != 'Y') && (response != 'n') && (response != 'N'));

    if ((response == 'y') || (response == 'Y'))
    {
        cout << "\n\tThere are 3 types of Allowance." << endl;
        cout << "\t\t1. House Rent Allowance." << endl;
        cout << "\t\t2. Transport Allowance." << endl;
        cout << "\t\t3. Medical Allowance." << endl;
        cout << "\t\t4. Entertainment Allowance." << endl;
        cout << "\t\t**Tips: Re-enter the type (1-4) to change the amount of \n\t\tallowance input before." << endl << endl;

        do
        {
            cout << "\tEnter the type of Allowance (1-4) or Enter 0 to skip: ";
            cin >> allowance_type;
        }
        while ((allowance_type != 1) && (allowance_type != 2) && (allowance_type != 3) && (allowance_type != 0));

        while (allowance_type != 0)
        {
            if (allowance_type == 1)
            {
                cout << "\tEnter House Rent Allowance(MYR): ";
                cin >> hr_allowance;
                cout << endl;
            }

            if (allowance_type == 2)
            {
                cout << "\tEnter Transport Allowance(MYR): ";
                cin >> tr_allowance;
                cout << endl;
            }

            if (allowance_type == 3)
            {
                cout << "\tEnter Medical Allowance(MYR): ";
                cin >> med_allowance;
                cout << endl;
            }

            if (allowance_type == 4)
            {
                cout << "\tEnter Entertainment Allowance(MYR): ";
                cin >> ent_allowance;
                cout << endl;
            }

            cout << "\tEnter the type of Allowance (1-4)or Enter 0 to skip: ";
            cin >> allowance_type;

        } ;

        //Calculate total allowance
        total_allowance = hr_allowance + tr_allowance + med_allowance + ent_allowance;

        cout << "\n\tEmployee House Rent Allowance: RM " << fixed << setprecision(2) << hr_allowance << endl;
        cout << "\tEmployee Transport Allowance: RM " << fixed << setprecision(2) << tr_allowance << endl;
        cout << "\tEmployee Medical Allowance: RM " << fixed << setprecision(2) << med_allowance << endl;
        cout << "\tEmployee Entertainment Allowance: RM " << fixed << setprecision(2) << ent_allowance << endl << endl;
        cout << "\tEmployee Total Allowance: RM " << fixed << setprecision(2) << total_allowance << endl << endl;
    }

    //calculate gross salary
    gross_salary = basic_salary + total_otpay + total_allowance;

    cout << "\nGross Salary" << endl;
    cout << "------------" << endl << endl;
    cout << "Gross Salary = Basic Salary + Total OT Pay + Total Allowance" << endl;
    cout << "\tEmployee Gross Salary: RM " << fixed << setprecision(2) << gross_salary << endl << endl;

    //Calculate EPF
    cout << "\nEPF" << endl;
    cout << "---" << endl << endl;
    cout << "Calculation of EPF is based on government guideline." << endl;
    cout << "Enter Employee EPF rate(%) (8 or 11 only): ";
    cin >> epf_rate;

    while ((epf_rate != 8) && (epf_rate != 11))
    {
        cout << "Wrong Input! Enter Employee EPF rate(%) (8 or 11 only): ";
        cin >> epf_rate;
    }

    epf = gross_salary * epf_rate / 100;

    cout << "\tEPF: RM " << epf << endl << endl;

    //Calculate SOCSO;
    cout << "\nSOCSO" << endl;
    cout << "-----" << endl << endl;
    cout << "Calculation of SOCSO is based on government guideline." << endl;
    if (gross_salary <= 0)
        socso = 0;

    else if ((gross_salary > 0) && (gross_salary <= 30))
        socso = 0.1;

    else if ((gross_salary > 30) && (gross_salary <= 50))
        socso = 0.2;

    else if ((gross_salary > 50) && (gross_salary <= 70))
        socso = 0.3;

    else if ((gross_salary > 70) && (gross_salary <= 100))
        socso = 0.4;

    else if ((gross_salary > 100) && (gross_salary <= 140))
        socso = 0.6;

    else if ((gross_salary > 140) && (gross_salary <= 200))
        socso = 0.85;

    else if ((gross_salary > 200) && (gross_salary <= 300))
        socso = 1.25;

    else if ((gross_salary > 300) && (gross_salary <= 400))
        socso = 1.75;

    else if ((gross_salary > 400) && (gross_salary <= 500))
        socso = 2.25;

    else if ((gross_salary > 500) && (gross_salary <= 600))
        socso = 2.75;

    else if ((gross_salary > 600) && (gross_salary <= 700))
        socso = 3.25;

    else if ((gross_salary > 700) && (gross_salary <= 800))
        socso = 3.75;

    else if ((gross_salary > 800) && (gross_salary <= 900))
        socso = 4.25;

    else if ((gross_salary > 900) && (gross_salary <= 1000))
        socso = 4.75;

    else if ((gross_salary > 1000) && (gross_salary <= 1100))
        socso = 5.25;

    else if ((gross_salary > 1100) && (gross_salary <= 1200))
        socso = 5.75;

     else if ((gross_salary > 1200) && (gross_salary <= 1300))
        socso = 6.25;

    else if ((gross_salary > 1300) && (gross_salary <= 1400))
        socso = 6.75;

    else if ((gross_salary > 1400) && (gross_salary <= 1500))
        socso = 7.25;

    else if ((gross_salary > 1500) && (gross_salary <= 1600))
        socso = 7.75;

    else if ((gross_salary > 1600) && (gross_salary <= 1700))
        socso = 8.25;

    else if ((gross_salary > 1700) && (gross_salary <= 1800))
        socso = 8.75;

    else if ((gross_salary > 1800) && (gross_salary <= 1900))
        socso = 9.25;

    else if ((gross_salary > 1900) && (gross_salary <= 2000))
        socso = 9.75;

    else if ((gross_salary > 2000) && (gross_salary <= 2100))
        socso = 10.25;

    else if ((gross_salary > 2100) && (gross_salary <= 2200))
        socso = 10.75;

    else if ((gross_salary > 2200) && (gross_salary <= 2300))
        socso = 11.25;

    else if ((gross_salary > 2300) && (gross_salary <= 2400))
        socso = 11.75;

    else if ((gross_salary > 2400) && (gross_salary <= 2500))
        socso = 12.25;

    else if ((gross_salary > 2500) && (gross_salary <= 2600))
        socso = 12.75;

    else if ((gross_salary > 2600) && (gross_salary <= 2700))
        socso = 13.25;

    else if ((gross_salary > 2700) && (gross_salary <= 2800))
        socso = 13.75;

     else if ((gross_salary > 2800) && (gross_salary <= 2900))
        socso = 14.25;

    else
        socso = 14.75;

    cout << "\tSOCSO: RM " << socso << endl << endl;

    //Calculate income tax
    cout << "\nIncome Tax" << endl;
    cout << "----------" << endl << endl;
    cout << "Calculation of Income Tax is based on government guideline." << endl;
    income_to_charge = gross_salary * 12;

    if (income_to_charge <= 0)
        annual_tax = 0;

    else if ((income_to_charge > 0 ) && (income_to_charge <= 5000))
        annual_tax = 0;

    else if ((income_to_charge > 5000) && (income_to_charge <= 10000))
        annual_tax = (income_to_charge - 5000) * 1 / 100;

    else if ((income_to_charge > 10000) && (income_to_charge <= 20000))
        annual_tax = ((income_to_charge - 10000) * 1 / 100) + 50;

    else if ((income_to_charge > 20000) && (income_to_charge <= 35000))
        annual_tax = ((income_to_charge - 20000) * 5 / 100) + 150;

    else if ((income_to_charge > 35000) && (income_to_charge <= 50000))
        annual_tax = ((income_to_charge - 35000) * 10 / 100) + 900;

    else if ((income_to_charge > 50000) && (income_to_charge <= 70000))
        annual_tax = ((income_to_charge - 50000) * 16 / 100) + 2400;

    else if ((income_to_charge > 70000) && (income_to_charge <= 100000))
        annual_tax = ((income_to_charge - 70000) * 21 / 100) + 5600;

    else if ((income_to_charge > 100000) && (income_to_charge <= 150000))
        annual_tax = ((income_to_charge - 100000) * 24 /100) + 11900;

    else if ((income_to_charge > 150000) && (income_to_charge <= 250000))
        annual_tax = ((income_to_charge - 150000) * 24 / 100) + 23900;

    else if ((income_to_charge > 250000) && (income_to_charge <= 400000))
        annual_tax = ((income_to_charge - 250000) * 24.5 / 100) + 47900;

    else if ((income_to_charge > 400000) && (income_to_charge <= 600000))
        annual_tax = ((income_to_charge - 400000) * 25 / 100) + 84650;

    else if ((income_to_charge > 600000) && (income_to_charge <= 1000000))
        annual_tax = ((income_to_charge - 600000) * 26 / 100) + 134650;

    else
        annual_tax = ((income_to_charge - 1000000) * 28 / 100) + 238650;

    tax = annual_tax / 12;

    cout << "\tIncome Tax: RM " << tax << endl << endl;

    //Calculate deduction
    cout << "\nDeduction" << endl;
    cout << "---------" << endl << endl;

    deduction = epf + socso + tax;

    cout << "Deduction = EPF + SOCSO + Income Tax" << endl;
    cout << "\tEmployee Deduction: RM " << fixed << setprecision(2) << deduction << endl << endl;

    //Calculate net salary
    cout << "\nNet Salary" << endl;
    cout << "----------" << endl << endl;

    net_salary = gross_salary - deduction;

    cout << "Net Salary = Gross Salary - Deduction" << endl;
    cout << "\tEmployee Net Salary: RM " << fixed << setprecision(2) << net_salary << endl << endl;

    cout << "\n\n-----------------------------------------------------------" << endl;

    //Print info
    do
    {
        cout << "Printing final information. Press 'y' to proceed. ";
        cin >> response;
    }
    while ((response != 'y') && (response != 'Y'));


    if ((response == 'y') || (response == 'Y'))
    {
        cout << "\n\n-----------------------------------------------------------" << endl;

        cout << "\nFinal Info" << endl;
        cout << "------------" << endl << endl;
        cout << "Employee Name: " << employee_name << endl;
        cout << "Employee ID: " << employee_id << endl;
        cout << "Employee Position: " << employee_position << endl;
        cout << "Employee Basic Salary: RM " << fixed << setprecision(2) << basic_salary << endl;
        cout << "Employee Total OT Pay: RM " << fixed << setprecision(2) << total_otpay << endl;
        cout << "Employee Total Allowance: RM " << fixed << setprecision(2) << total_allowance << endl;
        cout << "Employee Gross Salary: RM " << fixed << setprecision(2) << gross_salary << endl;
        cout << "Employee Deduction: RM " << fixed << setprecision(2) << deduction << endl;
        cout << "\nEmployee Final Net Salary: RM " << fixed << setprecision(2) << net_salary << endl;

        cout << "\n\n-----------------------------------------------------------" << endl;

    }

}

