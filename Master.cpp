#include <iostream>
using namespace std;

/* Đây là khung sườn đại khái (chưa đầy đủ) của Product, căn theo khung này và thêm mắm dặm muối
--Tách nhánh(branche) để lấy bản sao của master rồi code, chỉnh sửa.
Khi nào code ok, chạy tốt thì merge từ branche lên master.
--Trong lúc code, dĩ nhiên cần thêm function, thấy thiếu function nào thì bổ sung thêm vào
--Tự thêm parameter phù hợp vào prototype của function
--Nhớ comment dòng code để tui hiểu nhe
*/


void SignUp_LogIn(); // dùng lúc mới vào game, hàm này có thể gồm 2 hàm nhỏ: đăng kí, đăng nhập

void printBoard();
//
//
//

void checkValidMatching(); // gọi hàm này để kiểm tra ghép cặp có được không
void check_I_Matching(); // hàm này nằm trong hàm checkValidMatching
void check_L_Matching(); // hàm này nằm trong hàm checkValidMatching
void check_U_Matching(); // hàm này nằm trong hàm checkValidMatching
void check_Z_Matching(); // hàm này nằm trong hàm checkValidMatching

void checkEndGame(); // kiểm tra có còn cặp nào không

void countTime(); // đếm thời gian hoàn thành bàn chơi

int main()
{

}