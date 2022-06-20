#include <iostream>
#include <fstream>
#include <string>
#include <Queue.h>

using namespace std;  // move size till after output

int main()
{
    int seats, size, riders, train;
    int size1, size2, size3, size4;         // Group sizes
    string group1, group2, group3, group4;  // Group names
    bool validate;

    ifstream fin;
    fin.open( "riders.txt" );
    if( !fin )
    {
	cout << "File failed to open. Please check input." << endl;
    }

    train = 0;       // set trains to zero for output
    fin >> seats;    // get seat size from input file

    while ( validate == false )
    {
        Queue coaster;

        if ( group2.empty() || group3.empty() || group4.empty() )
        {
            fin >> group1 >> size1;
            if ( size1 > coaster.size() )
                cout << "Group 1 cannot fit" << endl;
        }
        else if ( group4.empty() && !group3.empty() )
        {
            group1 = group3;
        }
        else if ( group3.empty() && !group2.empty() )
        {
            group1 = group2;
        }

        for ( int i =1; i <= size1; i++ )
        {
            coaster.enqueue( group1 );
        }

        fin >> group2 >> size2;

        if ( size2 <= seats-size1 )
        {

            for ( int i = size1; i <= size1+size2; i++ )
            {
                coaster.enqueue( group2 );
            }

            fin >> group3 >> size3;

            if ( size3 <= seats-coaster.size() )
            {
                for ( int i = size1; i <= size1+size2; i++ )
                {
                    coaster.enqueue( group3 );
                }

                fin >> group4 >> size4;

                if ( size4 <= seats-coaster.size() )
                {
                    for ( int i = size1+size2+size3; i <= seats; i++ )
                    {
                        coaster.enqueue( group4 );
                    }

                    cout << "Train #" << train << endl;
                    cout << "------------------------" << endl;
                    for ( int i = 1; i <= size1; i++ )
                    {
                        cout << group1 << i << endl;
                    }
                    for ( int i = size1; i <= size1+size2; i++ )
                    {
                        cout << group2 << i << endl;
                    }
                    for ( int i = size1+size2; i <= size1+size2+size3; i++ )   //checked
                    {
                        cout << group3 << i << endl;
                    }
                    for ( int i = size1+size2+size3; i <= coaster.size(); i++ )
                    {
                        cout << group4 << i << endl;
                    }
                }
                cout << "Train #" << train << endl;
                cout << "------------------------" << endl;
                for ( int i = 1; i <= size1; i++ )
                {
                    cout << group1 << i << endl;
                }
                for ( int i = size1; i <= size1+size2; i++ )  // checked
                {
                    cout << group2 << i << endl;
                }
                for ( int i = size1+size2; i <= coaster.size(); i++ )
                {
                    cout << group3 << i << endl;
                }
            }

            cout << "Train #" << train << endl;
            cout << "------------------------" << endl;
            for ( int i = 1; i <= size1; i++ )
            {
                cout << group1 << i << endl;
            }
            for ( int i = size1; i <= coaster.size(); i++ )  //checked
            {
                cout << group2 << i << endl;
            }
        }

        cout << "Train #" << train << endl;
        cout << "------------------------" << endl;
        for ( int i = 1; i <= size1; i++ )
        {
            cout << group1 << i << endl;
        }
    }

    return 0;

}

