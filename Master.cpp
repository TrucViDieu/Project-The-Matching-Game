#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <conio.h> 
#include <windows.h> 
using namespace std;

struct vertical{
    string Line1, Line2, Line3, Line4;
};

struct cell{
    string UpperHori;
    string BottomHori;
    vertical VerLine;
    char figure;
    bool color;
};
/* Đây là khung sườn đại khái (chưa đầy đủ) của Product, căn theo khung này và thêm mắm dặm muối
--Tách nhánh(branche) để Blấy bản sao của master rồi code, chỉnh sửa.
Khi nào code ok, chạy tốt thì merge từ branche lên master.
--Trong lúc code, dĩ nhiên cần thêm function, thấy thiếu function nào thì bổ sung thêm vào
--Tự thêm parameter phù hợp vào prototype của function
--Nhớ comment dòng code để tui hiểu nhe
*/

HANDLE hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);

//void SignUp_LogIn(); // dùng lúc mới vào game, hàm này có thể gồm 2 hàm nhỏ: đăng kí, đăng nhập
<<<<<<< Updated upstream

void generateBoard(cell Board[][8]);
=======
>>>>>>> Stashed changes

void chooseSizeOfTable(int &Rows, int &Cols);
void generateBoard(cell** &Board, int Rows, int Cols);

void print_UpperHorizontalLine(cell** Board, int Row, int Cols, int M_Row, int M_Col);
void print_BottomHorizontalLine(cell** Board, int Row, int Cols, int M_Row, int M_Col);
void print_VerticalLine(cell** Board, int Row, int Cols, int M_Row, int M_Col);
void printBoard(cell** Board, int Rows, int Cols, int M_Row, int M_Col);


void movingEffects(cell** Board, int Rows, int Cols);

//void checkValidMatching(); // gọi hàm này để kiểm tra ghép cặp có được không
//void check_I_Matching(); // hàm này nằm trong hàm checkValidMatching
//void check_L_Matching(); // hàm này nằm trong hàm checkValidMatching
//void check_U_Matching(); // hàm này nằm trong hàm checkValidMatching
//void check_Z_Matching(); // hàm này nằm trong hàm checkValidMatching

//void checkEndGame(); // kiểm tra có còn cặp nào không

//void countTime(); // đếm thời gian hoàn thành bàn chơi

int main()
{
<<<<<<< Updated upstream
    cell Board[8][8];

    printBoard(Board);
=======
    cell** Board;
    int Rows, Cols;
    chooseSizeOfTable(Rows, Cols);
    generateBoard(Board, Rows, Cols);
    movingEffects(Board, Rows, Cols);
    

}
void chooseSizeOfTable(int &Rows, int &Cols)
{
    int number;
    cout << "Chon kich thuoc cua bang (Nhap 1 hoac 2 hoac 3)~ " << "\n";
    cout << "[1] - 4 x 4" << "\n";
    cout << "[2] - 6 x 6 " << "\n";
    cout << "[3] - 8 x 8" << "\n";
    cout << "Toi chon: "; cin >> number;
    while(number != 1 && number != 2 && number != 3)
    {
        cout << "Nhap sai, moi nhap lai" << "\n";
        cout << "Toi chon: "; cin >> number;
    }
    switch(number)
    {
        case 1: 
        {
            Rows = 6; // size 4x4 , cần chừa hàng trống trên và dưới, trái và phải nên thành 6x6
            Cols = 6;
            break;
        }
        case 2:
        { 
            Rows = 8; // size 6x6 , cần chừa hàng trống trên và dưới, trái và phải nên thành 8x8
            Cols = 8;
            break;
        }
        case 3:
        {
            Rows = 10; // size 8x8 , cần chừa hàng trống trên và dưới, trái và phải nên thành 10x10
            Cols = 10;
            break;
        }
    }

>>>>>>> Stashed changes
}

void print_UpperHorizontalLine(cell** Board, int Row, int Cols, int M_Row, int M_Col)
{
    for (int Col = 0; Col < Cols; Col++)
    {
        if (Row == 0 || Row == Cols - 1) 
            Board[Row][Col].UpperHori = "         ";
        else
        {
            if (Col == 0 || Col == Cols - 1)
                Board[Row][Col].UpperHori = "         ";
            else
                Board[Row][Col].UpperHori = " ------- ";
        }  
        if (Row == M_Row && Col == M_Col) SetConsoleTextAttribute(hConsoleColor, 4);       
        if (Board[Row][Col].color) SetConsoleTextAttribute(hConsoleColor, 4);    
        cout << Board[Row][Col].UpperHori;
        SetConsoleTextAttribute(hConsoleColor, 11);
    }
    cout << "\n";
}
void print_BottomHorizontalLine(cell** Board, int Row, int Cols, int M_Row, int M_Col)
{
    for (int Col = 0; Col < Cols; Col++)
    {
        if (Row == 0 || Row == Cols - 1)
            Board[Row][Col].BottomHori = "         ";
        else
        {
            if (Col == 0 || Col == Cols - 1)
                Board[Row][Col].BottomHori = "         ";
            else
                Board[Row][Col].BottomHori = " ------- ";
        }
        if (Row == M_Row && Col == M_Col) SetConsoleTextAttribute(hConsoleColor, 4); // kiểm tra có phải là ô đã bắt không, có thì in màu ô đó
        if (Board[Row][Col].color) SetConsoleTextAttribute(hConsoleColor, 4);
        cout << Board[Row][Col].BottomHori;
        SetConsoleTextAttribute(hConsoleColor, 11);   
    }
    cout << "\n";
}
void print_VerticalLine(cell** Board, int Row, int Cols, int M_Row, int M_Col)
{
    int Col;
    for(Col = 0; Col < Cols; Col++)
    {
        if (Row == 0 || Row == Cols - 1)
            Board[Row][Col].VerLine.Line1 = "         ";
        else
        {
            if (Col == 0 || Col == Cols - 1)
                Board[Row][Col].VerLine.Line1 = "         ";
            else
                Board[Row][Col].VerLine.Line1 = "|       |";
        }
        if (Row == M_Row && Col == M_Col) SetConsoleTextAttribute(hConsoleColor, 4); // kiểm tra có phải là ô đã bắt không, có thì in màu ô đó
        if (Board[Row][Col].color) SetConsoleTextAttribute(hConsoleColor, 4);
        if (Board[Row][Col].color) SetConsoleTextAttribute(hConsoleColor, 4);
        cout << Board[Row][Col].VerLine.Line1;
        SetConsoleTextAttribute(hConsoleColor, 11);         
    }
    cout << "\n";
    //
    for(Col = 0; Col < Cols; Col++)
    {
        if (Row == 0 || Row == Cols - 1)
        {
            Board[Row][Col].VerLine.Line2 = "     ";
            Board[Row][Col].VerLine.Line3 = "    ";
            cout << Board[Row][Col].VerLine.Line2 << Board[Row][Col].VerLine.Line3;
        }
        else 
        {
            if (Col == 0 || Col == Cols - 1)
            {
                Board[Row][Col].VerLine.Line2 = "     ";
                Board[Row][Col].VerLine.Line3 = "    ";
                cout << Board[Row][Col].VerLine.Line2 << Board[Row][Col].VerLine.Line3;
            }
            else
            {
                Board[Row][Col].VerLine.Line2 = "|   ";
                Board[Row][Col].VerLine.Line3 = "   |";
                if (Row == M_Row && Col == M_Col) SetConsoleTextAttribute(hConsoleColor, 4); // kiểm tra có phải là ô đã bắt không, có thì in màu ô đó
                if (Board[Row][Col].color) SetConsoleTextAttribute(hConsoleColor, 4);
                cout << Board[Row][Col].VerLine.Line2 << Board[Row][Col].figure << Board[Row][Col].VerLine.Line3;
                SetConsoleTextAttribute(hConsoleColor, 11);                 
            }
        }

    }
    cout << "\n";
    //
    for(Col = 0; Col < Cols; Col++)
    {
        if (Row == 0 || Row == Cols - 1)
            Board[Row][Col].VerLine.Line4 = "         ";
        else
        {
            if (Col == 0 || Col == Cols - 1)
                Board[Row][Col].VerLine.Line4 = "         ";
            else
                Board[Row][Col].VerLine.Line4 = "|       |";
        }
        if (Row == M_Row && Col == M_Col) SetConsoleTextAttribute(hConsoleColor, 4);// kiểm tra có phải là ô đã bắt không, có thì in màu ô đó
        if (Board[Row][Col].color) SetConsoleTextAttribute(hConsoleColor, 4);
        if (Board[Row][Col].color) SetConsoleTextAttribute(hConsoleColor, 4);
        cout << Board[Row][Col].VerLine.Line4;
        SetConsoleTextAttribute(hConsoleColor, 11); 
    }    
    cout << "\n";
}

void printBoard(cell** Board, int Rows, int Cols, int M_Row, int M_Col)
{
    for (int Row = 0; Row < Rows; Row++){
        print_UpperHorizontalLine(Board, Row, Cols, M_Row, M_Col);
        print_VerticalLine(Board, Row, Cols, M_Row, M_Col);
        print_BottomHorizontalLine(Board, Row, Cols, M_Row, M_Col);
    }
}

void generateBoard(cell** &Board, int Rows, int Cols)
{
    // các kí tự có số lần xuất hiện giống nhau
    int numOfChar, numOfOccurences; // numOfOccurences giữ số lần xuất hiện của kí tự
    int index, number;

    Board = new cell *[Rows];
    for (int i = 0; i < Rows; i++){
        Board[i] = new cell[Cols];
    }
    // kiểm tra người dùng đã chọn board nào để xác định số loại kí tự được random

    if (Rows == 6)                                         
    {
        numOfChar = 4; // 4 kí tự A, B, C, D
        numOfOccurences = 4;
    }
    else if (Rows == 8)
    {
        numOfChar = 6; // 6 kí tự A, B, C, D, E, F
        numOfOccurences = 6;
    }
    else
    {
        numOfChar = 8; // 8 kí tự A, B, C, D, E, F, G, H
        numOfOccurences = 8;
    }

    int* count = new int[numOfChar];
    // gán số lần xuất hiện của tất cả các kí tự bằng 0
    for (int i = 0; i < numOfChar; i++)
        count[i] = 0;

    srand(time(NULL));
    for (int Row = 1; Row < Rows - 1; Row++)
    {
        for (int Col = 1; Col < Cols - 1; Col++)
        {
            while(true)
            {                                               // number giữ mã ascii của kí tự
                index = rand()%numOfChar;                   // nếu numOfChar = 4, index từ 0 -> 3, tương ứng number từ 65 -> 68
                number = 65 + index;                        // nếu numOfChar = 6, index từ 0 -> 5, tương ứng number từ 65 -> 70
                if (count[index] < numOfOccurences)         // nếu numOfChar = 8, index từ 0 -> 7, tương ứng number từ 65 -> 72
                {
                    count[index]++;
                    Board[Row][Col].figure = number;
                    break;
                }
            }
        }
    }
}
<<<<<<< Updated upstream
=======
void movingEffects(cell** Board, int Rows, int Cols)
{
    char keyboard;
    // khởi tạo tất cả các ô đều không có màu
    for (int Row = 1; Row < Rows - 1; Row++)
    {
        for (int Col = 1; Col < Cols - 1; Col++)
            Board[Row][Col].color =  false;
    }

    int M_Row = 0, M_Col = 0; // 2 biến có tác dụng đánh dấu ô đã bắt đầu tiên
    int flag = 20; 
    // bắt đầu vào game, phím đang ở vị trí ô đầu nên ô đầu có màu 
    Board[1][1].color =  true;
    printBoard(Board, Rows, Cols, M_Row, M_Col);
    Board[1][1].color =  false;
    int Row = 1, Col = 1;
    while(flag >= 0) // tạm thời để vậy, sau này sẽ thay thế đkiện bằng hàm endgame
    {
        keyboard = getch(); // bắt phím
  
        if (keyboard == 77) // phím phải
        {
            Col++;
            if (Col > Cols - 2) Col--;
            Board[Row][Col].color =  true;
        }
        if (keyboard == 75) // phím trái
        {
            Col--;
            if (Col < 1) Col++;
            Board[Row][Col].color =  true;
        }
        if (keyboard == 72) // phím lên
        {
            Row--;
            if (Row < 1) Row++;
            Board[Row][Col].color =  true;
        }
        if (keyboard == 80) // phím xuống
        {
            Row++;
            if (Row > Rows - 2) Row--;
            Board[Row][Col].color =  true;
        }
        if (keyboard == 13) // enter
        {
        	M_Row = Row; // giữ chỉ số của ô vừa bắt
        	M_Col = Col;
		}  
        system("cls"); // xóa board cũ
        printBoard(Board, Rows, Cols, M_Row, M_Col); // in board mới
        Board[Row][Col].color =  false; // gán lại màu ô vừa đi qua là false để không in màu ô đó nữa
        flag--;
    }
}
>>>>>>> Stashed changes
