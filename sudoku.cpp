#include<iostream>
#include<iomanip>


// Input sudoku
void inputSudoku(int arr[][9]){
    int i,j;

    std::cout << "Enter the values with a space!" << std::endl;
    
    for(i=0; i<9; i++){
        std::cout << "Enter " << i+1 << "th row: ";
        for(j=0; j<9; j++){
            std::cin >> arr[i][j];
        }
    }

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
    std::cout << "----------------------------" << std::endl;
}


// clear console
void clear(){
    #if defined (_WIN32) || defined (_WIN64)
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPEL__)
        system("clear");
    #endif
}


// check is the value valid for the position
bool isValid(int val, int x, int y, int arr[][9]){
    int i,j;
    int initialx, finalx;
    int initialy, finaly;
    bool match = false;

    if(!match){
        for(i=0; i<9; i++){
            if(i!=y){
                if(arr[x][i] == val){
                    match = true;
                    break;
                }
            }

        }
    }

    if(!match){
        for(i=0; i<9; i++){
            if(i!=x){
                if(arr[i][y] == val){
                    match = true;
                    break;
                }
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
                if(i!=x && j!=y){
                    if(arr[i][j] == val){
                        match = true;
                        break;
                    }
                }
            }
        }
    }

    return !match;
}


// is the given sudoku is correct
bool isCorrect(int arr[][9]){
    int i,j;

    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            if(arr[i][j] != 0){
                if(!isValid(arr[i][j], i, j, arr)){
                    return false;
                }
            }
        }
    }
    return true;
}


// solve the function
void solve(int arr[][9], int* cont){
    int i,j;
    int val;

    if(!isCorrect(arr)){
        std::cout << "Wrong Input" << std::endl;
        return;
    }

    if(*cont == 1){
        for(i=0; i<9; i++){
            for(j=0; j<9; j++){
                if(arr[i][j] == 0){
                    for(val=1; val<=9; val++){
                        if(isValid(val,i,j,arr)){
                            arr[i][j] = val;
                            solve(arr, cont);
                            arr[i][j] = 0;
                        }
                    }
                    return;
                }
            }
        }
        std::cout << "The solved sudoku is -" << std::endl;
        display(arr);
        std::cout << "Want more solve? Enter '1'/'0' ! ";
        std::cin >> *cont;
        clear();
    }

    return;
}



// main function
int main(){

    int arr[9][9];
    int cont = 1;

    inputSudoku(arr);
    
    display(arr);

    solve(arr, &cont);

    return 0;
}


