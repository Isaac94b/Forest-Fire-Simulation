

#include <vector>
#include <math.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
using namespace std;
int size;
int tempForestSize;
vector<vector<int> > forest;
vector<vector<int> > tempForest;

//--------------------------------------------------------------------------------
void initializeForest(){
    
    char c;
    ifstream f;
    f.open ("file.txt");    
    size =5; 
    tempForestSize = size+2; // the size of the temporary matrix
    
    vector<vector<int> > forest1(size,vector<int>(size));    
    forest = forest1;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
             f.get(c);
            if (c == '\n')
                j = -1;
            forest[i][j] = c - '0';
        }
    }
    
    f.close();   
}

//---------------------------------------------------------------------------------------------
void initializeTempForest(char c){
    
    vector<vector<int> > forest1(tempForestSize, vector<int>(tempForestSize));
    
    tempForest = forest1;
    int iMainForest = 0;
    int jMainForest = 0;
    
    for (int i = 0; i < tempForestSize; i++) {
        for (int j = 0; j < tempForestSize; j++) {
            if ((i == 0 && (j >= 0 || j == tempForestSize-1)) || ( i >= 0 && (j == 0 || j == tempForestSize-1)) || (i == tempForestSize-1 && j >= 0)) {
                tempForest[i][j] = c;
            } else {
                tempForest[i][j] = forest[iMainForest][jMainForest];
                jMainForest++;
            }
        }
        
        if (i != 0 && i != tempForestSize-1) {
            iMainForest++;
            jMainForest = 0;
        }
    }
    
}

// -------------------------------------------------------------------------------------------------
int isNeighborOnFire(int x, int y){
    
    int startX = x;
    int endX = startX+3;
    int startY = y;
    int endY = startY+3;

    for (int i = startX; i < endX; i++) {
        for (int j = startY; j < endY; j++) {
                if (tempForest[i][j] == 5) {
                    return 1;
            }
        }
    }
    
    return 0;
}

//----------------------------------------------------------------------------------------------
void updateForest(){
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (forest[i][j] != 9 && forest[i][j] != 0) { // if it's not an ash or a void proceed the treatment
                if (forest[i][j] == 1) {                    // if it is a tree check its neighbors
                    if (isNeighborOnFire(i, j) == 1) {        // if there is at least one fire the current tree will burn
                        forest[i][j] = 5;
                    }
                }else if (forest[i][j] == 5)                // if it is a fire, turn it into an ash
                    forest[i][j] = 9;
            }
        }
    }
    
}

//---------------------------------------------------------------------------------------
void displayForest(){
    
    string temp = " ";
    
    for (int i = 0; i < size; i++) {
        temp.append("  --  ");
    }
    
    for (int i = 0; i < size; i++) {
        cout << temp << endl << endl;
        cout << "|  ";
        for (int j = 0; j < size; j++) {
            cout << forest[i][j] << "  |  ";
        }
        cout << "\n" << endl;
    }
    cout << temp << endl;
}

// --------------------------------------------------------------------------------
void displayTempForest(){
    
    string temp = " ";
    
    for (int i = 0; i < tempForestSize; i++) {
        temp.append("  --  ");
    }
    
    for (int i = 0; i < tempForestSize; i++) {
        cout << temp << endl << endl;
        cout << "|  ";
        for (int j = 0; j < tempForestSize; j++) {
            cout << tempForest[i][j] << "  |  ";
        }
        cout << "\n" << endl;
    }
    cout << temp << endl;
}
//--------------------------------------------------------------------------------------------------
int main(int argc, const char * argv[]) {
   
    char defaultState;  // contains the default state for the padding
    int hourToburn;     // contains the time for the tree to burn (time to change from the current state to the next state)
    int timeToEndTesting; // contains the time in which the phenomena will last
    
    cout << "Enter the amount of time for the tree to burn : ";
    cin >> hourToburn;
    cout << "\n";
    cout << "Enter the time necessary to complete the test : ";
    cin >> timeToEndTesting;
    cout << "\n";
    cout << "Enter the default state for this phenomena : " << endl;
    cout << " 0 - 5 - 1 - 9 " << endl;
    cout << "the default state : ";
    cin >> defaultState;
    cout << "\n" << endl;
    
    initializeForest();
    
    for (int i = 0; i < timeToEndTesting; i++) {
        
        cout << "   -------------------- " <<endl;
        cout << "  | THE STATE NUMBER " << i <<" |" <<endl;
        cout << "   -------------------- " <<endl;
        
        initializeTempForest(defaultState);
        displayForest();
        updateForest();
        usleep(hourToburn*1000000);
        cout << "\n" <<endl;
       // system("clear");        // this line is useless until it's used on the terminal prompt ('clear' on Unix based/Unix like systems,  'cls' on Windows)
                                // it is used to clear the window for the next state to appear (for an elegant displaying)
    }
    
    return 0;

}
