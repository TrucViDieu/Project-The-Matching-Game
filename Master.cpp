#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
struct vertical{
    string Line1, Line2, Line3, Line4;
};

struct cell{
    string UpperHori;
    string BottomHori;
    vertical VerLine;
    char figure;
};



/* Đây là khung sườn đại khái (chưa đầy đủ) của Product, căn theo khung này và thêm mắm dặm muối
--Tách nhánh(branche) để lấy bản sao của master rồi code, chỉnh sửa.
Khi nào code ok, chạy tốt thì merge từ branche lên master.
--Trong lúc code, dĩ nhiên cần thêm function, thấy thiếu function nào thì bổ sung thêm vào
--Tự thêm parameter phù hợp vào prototype của function
--Nhớ comment dòng code để tui hiểu nhe
*/


//void SignUp_LogIn(); // dùng lúc mới vào game, hàm này có thể gồm 2 hàm nhỏ: đăng kí, đăng nhập
void generateBoard(cell Board[][8]);

void print_UpperHorizontalLine(cell Board[][8], int Row);
void print_BottomHorizontalLine(cell Board[][8], int Row);
void print_VerticalLine(cell Board[][8], int Row);
void printBoard(cell Board[][8]);



//void checkValidMatching(); // gọi hàm này để kiểm tra ghép cặp có được không
//void check_I_Matching(); // hàm này nằm trong hàm checkValidMatching
//void check_L_Matching(); // hàm này nằm trong hàm checkValidMatching
//void check_U_Matching(); // hàm này nằm trong hàm checkValidMatching
//void check_Z_Matching(); // hàm này nằm trong hàm checkValidMatching

//void checkEndGame(); // kiểm tra có còn cặp nào không

//void countTime(); // đếm thời gian hoàn thành bàn chơi

int main()
{
    cell Board[8][8];
    int Row = 0;

    printBoard(Board);

}
void print_UpperHorizontalLine(cell Board[][8], int Row)
{
    for (int Col = 0; Col < 8; Col++)
    {
        Board[Row][Col].UpperHori = " ------- ";
        cout << Board[Row][Col].UpperHori;
    }
    cout << "\n";
}
void print_BottomHorizontalLine(cell Board[][8], int Row)
{
    for (int Col = 0; Col < 8; Col++)
    {
        Board[Row][Col].BottomHori = " ------- ";
        cout << Board[Row][Col].BottomHori;
    }
    cout << "\n";
}
void print_VerticalLine(cell Board[][8], int Row)
{
    int Col;
    for(Col = 0; Col < 8; Col++)
    {
        Board[Row][Col].VerLine.Line1 = "|       |";
        cout << Board[Row][Col].VerLine.Line1;
    }
    cout << "\n";
    //
    for(Col = 0; Col < 8; Col++)
    {
        Board[Row][Col].VerLine.Line2 = "|   ";
        Board[Row][Col].VerLine.Line3 = "   |";
        cout << Board[Row][Col].VerLine.Line2 << Board[Row][Col].figure << Board[Row][Col].VerLine.Line3;
    }
    cout << "\n";
    //
    for(Col = 0; Col < 8; Col++)
    {
        Board[Row][Col].VerLine.Line4 = "|       |";
        cout << Board[Row][Col].VerLine.Line4;
    }    
    cout << "\n";

}
void printBoard(cell Board[][8])
{
    generateBoard(Board);
    for (int Row = 0; Row < 8; Row++)
    {
        print_UpperHorizontalLine(Board, Row);
        print_VerticalLine(Board, Row);
        print_BottomHorizontalLine(Board, Row);   
    }
}
void generateBoard(cell Board[][8])
{
    int count[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int index, number;
    srand(time(NULL));
    for (int Row = 0; Row < 8; Row++){
        for (int Col = 0; Col < 8; Col++)
        {
            while(true){
                index = rand()%8; // [0-->7]
                number = 65 + index;
                if (count[index] < 8)
                {
                    count[index]++;
                    Board[Row][Col].figure = number;
                    break;
                }
            }
        }
    }
}