#include <iostream>
using namespace std;

int main()
{
    
    // VARIABLE DECLARATION
    string donor_name, gender;
    int age, weight, height;
    
    
    
    
    
    // DATA COLLECTION
    cout << "Donor Name: ";
    getline( cin, donor_name );
    
    if ( donor_name == "" )
    {
        cout << "--- You must enter a valid name." << endl;
        
        return -1;
    }
    
    
    
    cout << "Gender: ";
    getline( cin, gender );
    
    if ( gender != "Trans Male" && gender != "Trans Female" &&
         gender != "Queer" && gender != "Different" &&
         gender != "Male" && gender != "Female" )
    {
        cout << "--- You must enter a valid gender." << endl;
        
        return -1;
    }
    
    
    
    cout << "Age: ";
    cin  >> age;
    
    if ( age <= 0 )
    {
        cout << "--- You must enter a valid age." << endl;
        
        return -1;
    }
    
    
    
    cout << "Weight: ";
    cin  >> weight;
    
    if ( weight <= 0 )
    {
        cout << "--- You must enter a valid weight." << endl;
        
        return -1;
    }
    
    
    
    cout << "Height: ";
    cin  >> height;
    
    if ( height <= 0 )
    {
        cout << "--- You must enter a valid height." << endl;
        
        return -1;
    }

    
    
    
    
    // ELEGIBILITY EVALUATION
    if ( age < 16 || weight < 110 )
        
        {
            cout << "--- No, " << donor_name;
            cout << " you cannot donate blood." << endl;
        }
    
    
    
    else if ( gender == "Trans Male" || gender == "Trans Female" ||
              gender == "Queer" || gender == "Different" )
        
    {
        if ( age <= 22 )
        {
            cout << "--- No, " << donor_name;
            cout << " you cannot donate blood." << endl;
        }
        
        else
        {
            cout << "--- Yes, " << donor_name;
            cout << " you can donate blood." << endl;
        }
    }
    
    
    else if ( gender == "Male" )
        
    {
        if ( age >= 16 && age <= 22 )
        {
            if ( height < 60 )
            {
                cout << "--- No, " << donor_name;
                cout << " you cannot donate blood." << endl;
            }
            else
            {
                cout << "--- Yes, " << donor_name;
                cout << " you can donate blood." << endl;
            }
        }
        
        else
        {
            cout << "--- Yes, " << donor_name;
            cout << " you can donate blood." << endl;
        }
        
    }
    
    
    
    else if ( gender == "Female" )
        
    {
        if ( age >= 16 && age <= 22 )
        {
            if ( height < 58 )
            {
                cout << "--- No, " << donor_name;
                cout << " you cannot donate blood." << endl;
            }
            else if ( height == 58 && weight >= 146 )
            {
                cout << "--- Yes, " << donor_name;
                cout << " you can donate blood." << endl;
            }
            else if ( height == 59 && weight >= 142 )
            {
                cout << "--- Yes, " << donor_name;
                cout << " you can donate blood." << endl;
            }
            else
            {
                cout << "--- Yes, " << donor_name;
                cout << " you can donate blood." << endl;
            }
        }
        
        else
        {
            cout << "--- Yes, " << donor_name;
            cout << " you can donate blood." << endl;
        }
    }
    
    
    
    return 0;
    
}
