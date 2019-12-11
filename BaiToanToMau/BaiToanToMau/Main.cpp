#include <iostream>
#include <conio.h>
using namespace std;

/*
	BÀI TOÁN TÔ MÀU
	Cho đồ thị dưới dạng ma trận kề
	quy ước:
		- Có đường đi là 1, không có đường đi là 0
		- Màu đánh số từ 1, 2, 3, ....

	{0,1,0,1,0,0,0,0,0,1},
	{1,0,1,1,0,0,0,0,0,1},
	{0,1,0,0,1,1,1,0,0,0},
	{1,1,0,0,0,1,0,0,0,1},
	{0,0,1,0,0,1,0,1,0,0},
	{0,0,1,1,1,0,0,0,1,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,0,0,1,0,1,0,1,1},
	{0,0,0,0,0,1,0,1,0,1},
	{1,1,0,1,0,0,0,1,1,0}

	{0,1,1,1,0,1,0,0,0,1},
	{1,0,1,1,0,0,1,1,0,0},
	{1,1,0,1,1,1,1,0,0,0},
	{1,1,1,0,0,0,0,0,1,1},
	{0,0,1,0,0,1,0,1,0,1},
	{1,0,1,0,1,0,0,0,1,1},
	{0,1,1,0,0,0,0,1,1,0},
	{0,1,0,0,1,0,1,0,1,1},
	{0,0,0,1,0,1,1,1,0,1},
	{1,0,0,1,1,1,0,1,1,0},

	{0,1,0,1,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,1,1},
	{0,1,0,0,1,1,1,0,0,0},
	{1,1,0,0,0,1,0,0,0,0},
	{0,1,1,0,0,0,0,1,0,0},
	{1,0,1,1,0,0,0,1,1,0},
	{1,0,1,0,0,0,0,1,1,1},
	{0,0,0,0,1,1,1,0,1,1},
	{0,1,0,0,0,1,1,1,0,1},
	{1,1,0,0,0,0,1,1,1,0},

	{0,1,1,1,1,1,0,0,0,1},
	{1,0,1,1,1,1,1,0,0,1},
	{1,1,0,0,1,1,1,1,1,0},
	{1,1,0,0,1,1,0,0,1,1},
	{1,1,1,1,0,1,1,1,1,0},
	{1,1,1,1,1,0,0,1,1,1},
	{0,1,1,0,1,0,0,1,1,0},
	{0,0,1,0,1,1,1,0,1,1},
	{0,0,1,1,1,1,1,1,0,1},
	{1,1,0,1,0,1,0,1,1,0},

	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},

*/
int do_thi[10][10] = 
{
	{0,1,0,1,0,0,0,0,0,1},
	{1,0,1,1,0,0,0,0,0,1},
	{0,1,0,0,1,1,1,0,0,0},
	{1,1,0,0,0,1,0,0,0,1},
	{0,0,1,0,0,1,0,1,0,0},
	{0,0,1,1,1,0,0,0,1,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,0,0,1,0,1,0,1,1},
	{0,0,0,0,0,1,0,1,0,1},
	{1,1,0,1,0,0,0,1,1,0}
};

int dinh[10] = { 0,1,2,3,4,5,6,7,8,9 };
int bac[10] = { 0,0,0,0,0,0,0,0,0,0 };
int mau[10] = { 0,0,0,0,0,0,0,0,0,0 };

void Tinh_bac()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			if (do_thi[i][j] == 1)
				bac[i]++;
		}
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void sap_xep()
{
	for (int i = 0; i < 10; i++)
		for (int j = i + 1; j <= 10; j++)
			if (bac[i] < bac[j])
			{
				swap(bac[i], bac[j]);
				swap(dinh[i], dinh[j]);
			}
}


bool kiem_tra()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (do_thi[i][j] != do_thi[j][i]) return false;

	return true;
}

void to_mau()
{
	int k = 0; // khởi tạo màu k = 0
	// Duyệt lần lượt các đỉnh của đồ thị theo thứ tự các đỉnh có bậc cao nhất trước
	// Nếu gặp đỉnh chưa tô màu if (mau[dinh[0][i]] == 0) thì tăng màu k lên 1 cho đỉnh đó có màu k
	for(int i = 0;i < 10; i++)
		if (mau[dinh[i]] == 0)
		{
			k++;
			mau[dinh[i]] = k;
			// Sau đó duyệt các đỉnh còn lại không kề với đỉnh này với cùng màu k
			
			for (int j = i + 1; j < 10; j++)  
				// Nếu gặp đỉnh chưa tô màu thì duyệt các đỉnh kề với đỉnh đó xem có bị trùng màu không
				if (mau[dinh[j]] == 0)
				{
					int t;
					for (t = 0; t < 10; t++)
						// nếu đỉnh kề và trùng màu thì bỏ qua đỉnh đó và kiểm tra các đỉnh chưa tô còn lại khác để tô cùng màu k
						if (mau[t] == k && do_thi[dinh[j]][t] == 1 ) break;  
					// Nếu kiểm tra tất cả các đỉnh kề đều không trùng màu thì tô đỉnh đó với màu k
					if (t > 9) mau[dinh[j]] = k;											
				}
		}
}

int main()
{
	if (kiem_tra() == false) return -1;
	else cout << "Kiem tra: OK" << endl;

	Tinh_bac();
	cout << "Tinh bac: " << endl;
	for (int i = 0; i < 10; i++)
		cout << dinh[i] << " ";
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << bac[i] <<" ";
	cout << endl;


	sap_xep();
	cout << "Thu tu dinh sau khi sap xep:" << endl;
	for (int i = 0; i < 10; i++)
		cout << dinh[i] + 1 << " ";
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << bac[i] << " ";
	cout << endl;

	to_mau();
	cout << "Mau duoc to:" << endl;
	for (int i = 0; i < 10; i++)
		cout << dinh[i] + 1 << " ";
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << mau[dinh[i]] << " ";
	cout << endl;
	_getch();
	return 0;
}