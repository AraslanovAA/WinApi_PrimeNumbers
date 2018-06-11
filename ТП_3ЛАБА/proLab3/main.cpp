#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include <string>
#include <sstream>
#include <windowsx.h>
#include <TCHAR.H>
using namespace Gdiplus;
using namespace std;
#pragma comment (lib,"Gdiplus.lib")


HMENU hMenu, hFileMenu, hHelpMenu;
HINSTANCE hInstance;

// ��������� �������� CALLBACK �������
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc2(HWND hWnd2, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND text, text2, text_out, text_out_2, text_out_nums, text_out_0, hWnd2, rbutton, rbutton2, rbut, rbut2, rbutton3, rbutton4, button1, edit, buttonClose, hEditD1, text_out_nums2,
hEditD2, hEditD3, hEditD4, hEditD5, hEditD6, hEditD7, hEditD8, hEditD9, hEditD10,
hEditD11, hEditD12, hEditD13, hEditD14, hEditD15, hEditD16, textP1, textP2, textP3, textP4, textP5, textP6, textP7,
textP8, textP9, textP10, textP11, textP12, textP13, textP14, textP15, textP16, button2, buttonnext;
HWND arrayEdits1[10][10];
int mas1[16];
int flag = 1;
int n = 7;
int K_0;
int k = 0;
bool crutch = false;
bool Mycase = false;
TCHAR HELPMESSAGE_2[25] = { '�','�',' ','�','�','�','�','�','�','�',' ','�','�','�','�','�',' ','�','�','�','�','�','�','x' };
TCHAR HELPMESSAGE[25] = { ' ',' ','�','�','�','�','e','�','�',' ','�','�','�','�','a',' ','�','p','a','�','�','�','e',' ' };//22
TCHAR THEEND[6] = { '�','o','�','e','�' };
int step = 0, nullstep = 0;
int NumElements;
int arrNums[100][3];
bool FirstMethod;
int menu = 0;
int p = 1;
bool LastOp = FALSE;
int l = 99;
int r = 2;
int a = 1;
int mas2[16];
int DrawKey = 0;
TCHAR charBuffer[2];
bool ERR_NO_0_1 = false;
bool ERR_NO_SIMBOL = false;
int num;

// ������� WinAPI ��� ����� ����� � ���������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	// ����������� ������ ����
	// ��������� ���������� ���� WNDCLASSEX

	WNDCLASSEX wClass, wNewClass, elseClass;
	ZeroMemory(&wClass, sizeof(wClass)); // �������� ������
	ZeroMemory(&wNewClass, sizeof(wNewClass));
	ZeroMemory(&elseClass, sizeof(wNewClass));
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;

	// Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	// ��������� ��������� WNDCLASSEX
	wClass.cbSize = sizeof(wClass); // ������ ����� ������� ���������
	wClass.hbrBackground = (HBRUSH)COLOR_WINDOW; // ���������� ��� ����
	wClass.hInstance = hInstance; // hInstance window
	wClass.lpfnWndProc = (WNDPROC)WndProc; // ��������� ��������� ����
	wClass.lpszClassName = "CLASS_1"; // ��� ������

	wNewClass.cbSize = sizeof(wNewClass); // ������ ����� ������� ���������
	wNewClass.hbrBackground = (HBRUSH)COLOR_WINDOW; // ���������� ��� ����
	wNewClass.hInstance = hInstance; // hInstance window
	wNewClass.lpfnWndProc = (WNDPROC)WndProc2; // ��������� ��������� ����
	wNewClass.lpszClassName = "CLASS_2"; // ��� ������



	// ���� ��������� ������, �� ������� ���������
	if (!RegisterClassEx(&wClass))
	{
		int nResult = GetLastError();
		MessageBox(NULL, "����� ���� �� ��� ������!", "������", MB_ICONERROR);
	}

	if (!RegisterClassEx(&wNewClass))
	{
		int nResult = GetLastError();
		MessageBox(NULL, "����� ���� �� ��� ������!", "������", MB_ICONERROR);
	}



	// ������� ���� ��� ������ ������� WinApi CreateWindowEx
	HWND hWindow = CreateWindowEx(NULL,
		"CLASS_1", // ��� ������, ������� �� ���������� �����
		"����� ������� �����", // ��������� ����
		WS_TILED,
		300, // x ���������� �� �����������
		300, // y ���������� �� ���������
		270, // ������ ������������ ����
		350, // ������ ������������ ����
		NULL,
		NULL,
		hInstance, // ���������� ���������� ����������
		NULL);



	// ���� ���� �� ���� �������, �� ������ ���������
	if (!hWindow)
	{
		int nResult = GetLastError();
		MessageBox(NULL, "���� �� ���� �������!", "������", MB_ICONERROR);
	}

	hWnd2 = CreateWindowEx(NULL,
		"CLASS_2", // ��� ������, ������� �� ���������� �����
		"�������", // ��������� ����
		WS_TILED,
		200, // x ���������� �� �����������
		200, // y ���������� �� ���������
		660, // ������ ������������ ����
		530, // ������ ������������ ����
		hWindow,
		NULL,
		hInstance, // ���������� ���������� ����������
		NULL);

	if (!hWnd2)
	{
		int nResult = GetLastError();
		MessageBox(NULL, "���� �� ���� �������!", "������", MB_ICONERROR);
	}


	// ���������� ����
	ShowWindow(hWindow, SW_SHOW);
	UpdateWindow(hWindow);

	// ��������� ���������� ��� ��������� ���� MSG
	MSG msg;
	// �������� ������ �� ������� ��������� MSG
	ZeroMemory(&msg, sizeof(MSG));

	// ���� ��������� ���������
	for (;;)
	{
		BOOL const Status = GetMessage(&msg, NULL, 0, 0);

		if ((0 == Status) || (-1 == Status))
		{
			break;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	/*while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	*/
	GdiplusShutdown(gdiplusToken);
	return 0;
}

// ���������� ��������� ��������� ������ (WinApi)
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
	{

		rbut = CreateWindow(
			"BUTTON",
			"������ ����������",
			WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
			20,
			100,
			160,
			20,
			hwnd,
			(HMENU)3,
			hInstance,
			NULL
		);
		SendMessage(rbut, BM_SETCHECK, BST_CHECKED, 0);
		rbut2 = CreateWindow(
			"BUTTON",
			"������ ������",
			WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
			20,
			120,
			150,
			20,
			hwnd,
			(HMENU)4,
			hInstance,
			NULL
		);



		text = CreateWindow("STATIC", "������� ������� �������", WS_VISIBLE | WS_CHILD | WS_BORDER,
			10, 15, 220, 20, hwnd, (HMENU)10, NULL, NULL);
		text2 = CreateWindow("STATIC", "                     [2;99]", WS_VISIBLE | WS_CHILD | WS_BORDER,
			10, 35, 220, 20, hwnd, (HMENU)10, NULL, NULL);
		hEditD1 = CreateWindow("edit", "2", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_READONLY, 20, 70, 20, 25, hwnd, NULL, hInstance, NULL);
		EnableWindow(hEditD1, FALSE);
		hEditD2 = CreateWindow("edit", "99", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_NUMBER, 80, 70, 20, 25, hwnd, NULL, hInstance, NULL);
		hEditD3 = CreateWindow("edit", "0", WS_CHILD | false | WS_BORDER | ES_LEFT | ES_READONLY, 140, 70, 15, 25, hwnd, NULL, hInstance, NULL);


		sprintf(charBuffer, "%d", 1);
		SetWindowText(hEditD3, charBuffer);
		// ����� ����� ��������� �������� ���������� ����
		HWND buttonpitch = CreateWindow("BUTTON", "��������", WS_VISIBLE | WS_CHILD
			| WS_BORDER, 10, 260, 80, 30, hwnd, (HMENU)1, NULL, NULL);
		HWND buttonClose = CreateWindow("BUTTON", "�����", WS_VISIBLE | WS_CHILD
			| WS_BORDER, 170, 260, 60, 30, hwnd, (HMENU)2, NULL, NULL);


		break;
	}
	case WM_CTLCOLORSTATIC: {
		if ((HWND)lParam == GetDlgItem(hwnd, 10))
		{
			HDC hdc = (HDC)wParam;
			SetBkMode(hdc, TRANSPARENT);
			SetTextColor(hdc, RGB(0, 0, 178));//��������� � ������� �������� - �����
			return (int)GetStockObject(NULL_BRUSH);

		}

	}

	case WM_NCLBUTTONDOWN: {
		if (wParam == HTCAPTION) {
			return 0;
		}
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			// ��������� ������ (������� ������, ����, ����� ����� � �.�.)
		case 1:
		{
			ERR_NO_SIMBOL = FALSE;
			ERR_NO_0_1 = FALSE;
			mas2[0] = SendMessage(hEditD1, EM_LINELENGTH, -1, 0);
			mas2[1] = SendMessage(hEditD2, EM_LINELENGTH, -1, 0);


			for (int j = 0; j < 2; j++)
			{
				if (mas2[j] == 0) {
					MessageBox(NULL, "������� �������", "������", MB_ICONERROR);
					ERR_NO_SIMBOL = TRUE;
					break;
				}
			}
			if (ERR_NO_SIMBOL == FALSE) {
				SendMessage(hEditD1, WM_GETTEXT, (WPARAM)255, (LPARAM)charBuffer);
				mas1[0] = atoi(charBuffer);
				SendMessage(hEditD2, WM_GETTEXT, (WPARAM)255, (LPARAM)charBuffer);
				mas1[1] = atoi(charBuffer);



				for (int i = 0; i < 2; i++)
				{
					if ((mas1[i] == 0) || (mas1[i] == 1))
					{
						MessageBox(NULL, "����������� ����� �� 2 �� 99", "������", MB_ICONERROR);
						ERR_NO_0_1 = TRUE;
						break;
					}
				}
			}
			if ((ERR_NO_0_1 == FALSE) && (ERR_NO_SIMBOL == FALSE)) {
				ShowWindow(hWnd2, SW_SHOW);
			}
			break;
		}

		case 2:
		{

			PostQuitMessage(0);
			return 0;
			break;
		}
		case 3: {
			if (flag == 0)
			{
				SendMessage(rbut, BM_SETCHECK, BST_CHECKED, 0);
				SendMessage(rbut2, BM_SETCHECK, BST_UNCHECKED, 0);
				flag = 1;
				sprintf(charBuffer, "%d", 1);
				SetWindowText(hEditD3, charBuffer);
			}
			else
			{
				SendMessage(rbut, BM_SETCHECK, BST_UNCHECKED, 0);
				SendMessage(rbut2, BM_SETCHECK, BST_CHECKED, 0);
				flag = 0;
				sprintf(charBuffer, "%d", 0);
				SetWindowText(hEditD3, charBuffer);
			}
			break;
		}
		case 4: {
			if (flag == 0)
			{
				SendMessage(rbut2, BM_SETCHECK, BST_UNCHECKED, 0);
				SendMessage(rbut, BM_SETCHECK, BST_CHECKED, 0);
				flag = 1;
				sprintf(charBuffer, "%d", 1);
				SetWindowText(hEditD3, charBuffer);
			}
			else
			{
				SendMessage(rbut, BM_SETCHECK, BST_UNCHECKED, 0);
				SendMessage(rbut2, BM_SETCHECK, BST_CHECKED, 0);
				flag = 0;
				sprintf(charBuffer, "%d", 0);
				SetWindowText(hEditD3, charBuffer);
			}
			break;
		}


				break;

		}

		break;
	}

	case WM_DESTROY: // ��������� ������� ������ �������� ����
	{
		// ������� ������� ����
		PostQuitMessage(0);
		return 0;
		break;
	}
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}



LRESULT CALLBACK WndProc2(HWND hWnd2, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int testP = 1;
	HDC hdc;

	string tmp;
	switch (uMsg)
	{
	case WM_CREATE:
	{
		button2 = CreateWindow("BUTTON", "�������", WS_VISIBLE | WS_CHILD
			| WS_BORDER, 360, 450, 70, 30, hWnd2, (HMENU)100, NULL, NULL);

		buttonnext = CreateWindow("BUTTON", "��������� ���", WS_VISIBLE | WS_CHILD
			| WS_BORDER, 160, 450, 120, 30, hWnd2, (HMENU)101, NULL, NULL);


		break;
	}
	case WM_PAINT: {
		text_out_0 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | ES_READONLY,
			10, 300, 700, 40, hWnd2, NULL, NULL, NULL);
		text_out_nums = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | ES_READONLY,
			10, 340, 800, 40, hWnd2, NULL, NULL, NULL);
		text_out_nums2 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | ES_READONLY,
			10, 381, 800, 40, hWnd2, NULL, NULL, NULL);
		text_out = CreateWindow("EDIT", "�������� �� �����������", WS_VISIBLE | WS_CHILD | ES_READONLY,// | WS_BORDER
			10, 260, 800, 40, hWnd2, NULL, NULL, NULL);

		EnableWindow(text_out, FALSE);
		step = 0;nullstep = 2;
		int forArr = 0;
		SendMessage(hEditD2, WM_GETTEXT, (WPARAM)255, (LPARAM)charBuffer);
		int second = atoi(charBuffer);
		SendMessage(hEditD1, WM_GETTEXT, (WPARAM)255, (LPARAM)charBuffer);
		int first = atoi(charBuffer);
		NumElements = second - first + 1;
		int i = 0;
		menu = 1;
		for (i = 0;i < int(NumElements / 10);i++) {
			for (int j = 0;j < 10;j++) {
				arrNums[forArr][0] = first;
				arrNums[forArr][1] = 0;

				forArr++;


				arrayEdits1[i][j] = CreateWindow("STATIC", charBuffer, WS_VISIBLE | WS_CHILD | WS_BORDER,
					j * 40 + 10, 10 + i * 25, 40, 25, hWnd2, (HMENU)menu, NULL, NULL);
				menu++;
				sprintf(charBuffer, "%d", first);
				SetWindowText(arrayEdits1[i][j], charBuffer);
				first++;
			}
		}
		i = 0;
		for (int j = 0;j < NumElements % 10;j++) {
			arrNums[forArr][0] = first;
			arrNums[forArr][1] = 0;

			forArr++;
			arrayEdits1[int(NumElements / 10)][j] = CreateWindow("STATIC", charBuffer, WS_VISIBLE | WS_CHILD | WS_BORDER,
				j * 40 + 10, 10 + i * 25 + 25 * (int(NumElements / 10)), 40, 25, hWnd2, (HMENU)menu, NULL, NULL);
			sprintf(charBuffer, "%d", first);
			menu++;
			SetWindowText(arrayEdits1[int(NumElements / 10)][j], charBuffer);
			first++;
		}
		arrNums[89][2] = 1;
		SendMessage(hEditD3, WM_GETTEXT, (WPARAM)255, (LPARAM)charBuffer);
		arrNums[75][2] = 1;

		first = atoi(charBuffer);
		if (first == 1) {
			FirstMethod = true;
		}
		else
		{
			FirstMethod = false;
		}



	}
	case WM_CTLCOLORSTATIC: {
		if (DrawKey == 1) {

			HDC hdc = (HDC)wParam;
			SetBkMode(hdc, TRANSPARENT);
			SetTextColor(hdc, RGB(0, 255, 0));
			return (int)GetStockObject(NULL_BRUSH);

		}

	}

	case WM_NCLBUTTONDOWN: {
		if (wParam == HTCAPTION) {
			return 0;
		}
		break;
	}

	case WM_COMMAND:
	{

		switch (LOWORD(wParam))
		{
			// ��������� ������ (������� ������, ����, ����� ����� � �.�.)
		case 100:
		{
			p = 1;
			k = 0;
			LastOp = FALSE;
			DestroyWindow(text_out);
			DestroyWindow(text_out_2);
			//�������� ������
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					DestroyWindow(arrayEdits1[i][j]);
				}
			}
			ShowWindow(hWnd2, SW_HIDE);
			break;
		}
		case 101: {
			int w = 80;
			TCHAR DELETEDNUMBERS[1000] = { ' ',' ',' ',' ', ' ' };
			TCHAR DELETEDNUMBERS2[1000] = { ' ' };
			if (FirstMethod == TRUE) {//������ ����������		

				bool findP = false;
				do {//����� p
					if (k < NumElements) {
						if (arrNums[k][0] <= p) {
							k++;
						}
						else {
							if (arrNums[k][1] == 1) {
								k++;
							}
							else {
								p = arrNums[k][0];
								findP = true;
							}
						}
					}
					else
					{
						LastOp = true;
						findP = true;
					}
				} while (findP == false);




				if (LastOp == false) {
					K_0 = 0;
					bool findCom = FALSE;
					for (int i = k;i < NumElements;i++) {

						if ((arrNums[i][0] != p) && (arrNums[i][0] % p == 0) && (arrNums[i][1] == 0)) {
							findCom = true;
							arrNums[i][1] = 1;
							if (K_0 <= w) {
								sprintf(charBuffer, "%d", arrNums[i][0]);

								DELETEDNUMBERS[K_0] = ' ';

								K_0++;
								DELETEDNUMBERS[K_0] = charBuffer[0];
								K_0++;
								if (charBuffer[1] != '\0') {
									DELETEDNUMBERS[K_0] = charBuffer[1];
									K_0++;
								}
							}
							else {
								sprintf(charBuffer, "%d", arrNums[i][0]);

								DELETEDNUMBERS2[K_0 - w - 1] = ' ';

								K_0++;
								if (charBuffer[0] != '\0') {
									DELETEDNUMBERS2[K_0 - w - 1] = charBuffer[0];
									K_0++;
								}
								if (charBuffer[1] != '\0') {
									DELETEDNUMBERS2[K_0 - w - 1] = charBuffer[1];
									K_0++;
								}
							}
							/*sprintf(charBuffer, "%d", arrNums[i][0]);���� ��� ����� ����
							i_ = int(i / 10);
							j_ = i % 10;
							SetWindowText(arrayEdits1[i_][j_], charBuffer);*/

						}
					}

					SetWindowText(text_out_nums, DELETEDNUMBERS);
					SetWindowText(text_out_nums2, DELETEDNUMBERS2);

					sprintf(charBuffer, "%d", p);
					HELPMESSAGE[23] = charBuffer[0];
					HELPMESSAGE[24] = charBuffer[1];
					HELPMESSAGE_2[23] = charBuffer[0];
					HELPMESSAGE_2[24] = charBuffer[1];
					if (findCom == true) {
						SetWindowText(text_out_0, "�������� �����");
						SetWindowText(text_out, HELPMESSAGE);
					}
					else
					{
						SetWindowText(text_out_0, "");
						SetWindowText(text_out, HELPMESSAGE_2);
					}

				}

				else {//������ ���������, ������� ������ ����������
					SetWindowText(text_out, THEEND);
					DrawKey = 1;
					SetWindowText(text_out_0, "������� �����");
					int K = 0;
					int i_, j_;
					for (int e = 0;e < NumElements;e++) {
						if (arrNums[e][1] == 0) {
							sprintf(charBuffer, "%d", arrNums[e][0]);
							i_ = int(e / 10);
							j_ = e % 10;
							SetWindowText(arrayEdits1[i_][j_], charBuffer);

							sprintf(charBuffer, "%d", arrNums[e][0]);

							DELETEDNUMBERS[K] = ' ';
							K++;
							if (charBuffer[0] != '\0') {
								DELETEDNUMBERS[K] = charBuffer[0];
								K++;
							}
							if (charBuffer[1] != '\0') {
								DELETEDNUMBERS[K] = charBuffer[1];
								K++;
							}
						}


					}
					DrawKey = 0;
					SetWindowText(text_out_nums, DELETEDNUMBERS);
				}
			}


			else {//���
				SetWindowText(text_out, "");
				switch (step)
				{
				case 0: {
					K_0 = 0;
					for (int i = 0;i < NumElements;i++) {
						if (((arrNums[i][0] % 60) % nullstep == 0) && (arrNums[i][0] != nullstep) && (arrNums[i][1] == 0)) {
							arrNums[i][1] = 1;

							if (K_0 <= w) {

								sprintf(charBuffer, "%d", arrNums[i][0]);

								DELETEDNUMBERS[K_0] = ' ';

								K_0++;
								DELETEDNUMBERS[K_0] = charBuffer[0];
								K_0++;
								if (charBuffer[1] != '\0') {
									DELETEDNUMBERS[K_0] = charBuffer[1];
									K_0++;
								}
							}
							else {
								sprintf(charBuffer, "%d", arrNums[i][0]);

								DELETEDNUMBERS2[K_0 - w - 1] = ' ';

								K_0++;
								if (charBuffer[0] != '\0') {
									DELETEDNUMBERS2[K_0 - w - 1] = charBuffer[0];
									K_0++;
								}
								if (charBuffer[1] != '\0') {
									DELETEDNUMBERS2[K_0 - w - 1] = charBuffer[1];
									K_0++;
								}
							}
						}
					}
					SetWindowText(text_out_nums, DELETEDNUMBERS);
					SetWindowText(text_out_nums2, DELETEDNUMBERS2);
					if (nullstep == 5) {

						SetWindowText(text_out_0, "�������� ����� �� ������ 60 ������� 5");
						step++;
						nullstep = 4;
					}
					if (nullstep == 3) {
						SetWindowText(text_out_0, "�������� ����� �� ������ 60 ������� 3");
						nullstep = 5;
					}
					if (nullstep == 2) {
						SetWindowText(text_out_0, "�������� ����� �� ������ 60 ������� 2");
						nullstep++;
					}

					break;

				}
				case 1: {
					K_0 = 0;
					for (int i = 0;i < NumElements;i++) {
						if ((arrNums[i][1] == 0) && ((arrNums[i][0] % 60) % nullstep == 1)) {
							if ((arrNums[i][0] == n*n) || (arrNums[i][2] == 1)) {
								arrNums[i][1] = 1;
							}
							else {
								sprintf(charBuffer, "%d", arrNums[i][0]);

								DELETEDNUMBERS[K_0] = ' ';

								K_0++;
								DELETEDNUMBERS[K_0] = charBuffer[0];
								K_0++;
								if (charBuffer[1] != '\0') {
									DELETEDNUMBERS[K_0] = charBuffer[1];
									K_0++;
								}
							}
						}
					}
					if (nullstep == 6) {
						SetWindowText(text_out_nums, DELETEDNUMBERS);
						SetWindowText(text_out_0, "����� �� ������ 60, ������� ������� ������� �� 6 ������ 1, �� ������� ������� ��������");
						step = 3;
					}
					if (nullstep == 4) {
						SetWindowText(text_out_nums, DELETEDNUMBERS);
						SetWindowText(text_out_0, "����� �� ������ 60, ������� ������� ������� �� 4 ������ 1, �� ������� ������� ��������");
						nullstep = 6;
					}
					break;
				}
				case 3: {
					K_0 = 0;
					for (int i = 0;i < NumElements;i++) {
						if ((arrNums[i][1] == 0) && ((arrNums[i][0] % 60) % 12 == 11)) {

							sprintf(charBuffer, "%d", arrNums[i][0]);

							DELETEDNUMBERS[K_0] = ' ';

							K_0++;
							DELETEDNUMBERS[K_0] = charBuffer[0];
							K_0++;
							if (charBuffer[1] != '\0') {
								DELETEDNUMBERS[K_0] = charBuffer[1];
								K_0++;
							}
						}
					}

					SetWindowText(text_out_nums, DELETEDNUMBERS);
					SetWindowText(text_out_0, "����� �� ������ 60 ������� ������� ������� �� 12 ������ 11 �� ������� ������� ��������");
					step = 4;
				}
				case 4: {
					SetWindowText(text_out, THEEND);
					DrawKey = 1;
					SetWindowText(text_out_0, "������� �����");
					int K = 0;
					int i_, j_;
					for (int e = 0;e < NumElements;e++) {
						if (arrNums[e][1] == 0) {
							sprintf(charBuffer, "%d", arrNums[e][0]);
							i_ = int(e / 10);
							j_ = e % 10;
							SetWindowText(arrayEdits1[i_][j_], charBuffer);

							sprintf(charBuffer, "%d", arrNums[e][0]);

							DELETEDNUMBERS[K] = ' ';
							K++;
							if (charBuffer[0] != '\0') {
								DELETEDNUMBERS[K] = charBuffer[0];
								K++;
							}
							if (charBuffer[1] != '\0') {
								DELETEDNUMBERS[K] = charBuffer[1];
								K++;
							}
						}


					}
					DrawKey = 0;
					SetWindowText(text_out_nums, DELETEDNUMBERS);
				}
				default:
					break;
				}
			}

			break;
		}
		case WM_DESTROY: // ��������� ������� ������ �������� ����
		{
			// ������� ������� ����
			PostQuitMessage(0);
			return 0;
			break;
		}
		}
	}
	}

	return DefWindowProc(hWnd2, uMsg, wParam, lParam);
}
