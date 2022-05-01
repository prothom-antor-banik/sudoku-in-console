#include<iostream>
#include<iomanip>


// check is the value valid for the position
bool isValid(int val, int x, int y, int arr[][9]){
    int i,j;
    int initialx, finalx;
    int initialy, finaly;
    bool match = false;

    if(!match){
        for(i=0; i<9; i++){
            if(arr[x][i] == val){
                match = true;
                break;
            }
        }
    }

    if(!match){
        for(i=0; i<9; i++){
            if(arr[i][y] == val){
                match = true;
                break;
            }
        }
    }

    if(!match){
        initialx = (x/3)*3;
        finalx = initialx + 3;
        initialy = (y/3)*3;
        finaly = initialy + 3;
    
        for(i=initialx; i<finalx; i++){
            for(j=initialy; j<finaly; j++){
                if(arr[i][j] == val){
                    match = true;
                    break;
                }
            }
        }
    }

    return !match;
}


// display the board
void display(int arr[][9]){
    int i,j;
    for(i=0; i<9; i++){
        std::cout << "----------------------------" << std::endl;
        for(j=0; j<9; j++){
            if(arr[i][j] != 0)
                std::cout << "|" << std::setw(2) << std::setfill('0') << arr[i][j];
            else
                std::cout << "|" << "  ";
        }
        std::cout << "|" << std::endl;
    }

}



// solve the function
void solve(int arr[][9]){
    int i,j;
    int val;
    int run;

    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            if(arr[i][j] == 0){
                for(val=1; val<=9; val++){
                    if(isValid(val,i,j,arr)){
                        arr[i][j] = val;
                        solve(arr);
                        arr[i][j] = 0;
                    }
                }
                return;
            }
        }
    }
    std::cout << "The solved sudoku is -" << std::endl;
    display(arr);
    std::cin >> run;
    return;
}



// main function
int main(){

    int i,j;

    int arr[9][9];

    std::cout << "Enter the values!" << std::endl;
    
    for(i=0; i<9; i++){
        std::cout << "Enter " << i+1 << "th row: ";
        for(j=0; j<9; j++){
            std::cin >> arr[i][j];
        }
    }

    std::cout << "The Sudoku is - " << std::endl;
    display(arr);

    solve(arr);

    return 0;
}


