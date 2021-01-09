﻿#include <iostream>
#include <string>

using namespace std;

// 1. Khai báo cấu trúc dữ liệu ngăn xếp(STACK) - sách.
struct Book
{
	int ID;
	string Name;
	string Author;
};

struct _SNode
{
	Book _IData;
	_SNode* _PNext;
};

struct _SStack
{
	_SNode* PtrTop;
};

// 2. Khởi tạo DSLK.
void _init(_SStack& s);

// 3. Tạo 1 node cho DSLK.
void _inputBook(Book& b);
void _outputBook(Book b);
_SNode* _createNode(Book _IData);

// 4. Add head/tail cho DSLK.
void PUSH(_SStack& s, _SNode* _PN); // _addHead

// 5. Thiết kế hàm input/output.
void _input(_SStack& s);
void _output(_SStack s);

// 6. Xử lý các yêu cầu cho DSLK.
bool EMPTY(_SStack s);
void TOP(_SStack s); // Lấy ra phần tử đầu.

// 7. Giải phóng các phần tử trong DSLK.
void POP(_SStack& s); // Xóa phần tử đầu.

int main()
{
	_SStack s;
	_input(s);

	cout << "===================Thong Tin Danh Sach Cuon Sach===================" << endl;
	_output(s);

	system("pause");
	return 0;
}

void _init(_SStack& s)
{
	s.PtrTop = NULL;
}

void _inputBook(Book& b)
{
	cout << "Nhap ma so: ";
	cin >> b.ID;
	cin.ignore(255, '\n');

	cout << "Nhap ten cuon sach: ";
	getline(cin, b.Name);

	cout << "Nhap ten tac gia: ";
	getline(cin, b.Author);
}

void _outputBook(Book b)
{
	cout << "ID: " << b.ID << endl;
	cout << "Ten sach: " << b.Name << endl;
	cout << "Tac gia: " << b.Author << endl;
}

_SNode* _createNode(Book _IData)
{
	_SNode* _PNode = new _SNode;
	if (_PNode == nullptr)
	{
		return NULL;
	}
	_PNode->_IData = _IData;
	_PNode->_PNext = nullptr;

	return _PNode;
}

void PUSH(_SStack& s, _SNode* _PN)
{
	if (s.PtrTop == nullptr)
	{
		s.PtrTop = _PN;
	}
	else
	{
		_PN->_PNext = s.PtrTop;
		s.PtrTop = _PN;
	}
}

void _input(_SStack& s)
{
	_init(s); // Khởi tạo danh sách.
	// Nhập vào số lượng phần tử cần thêm vào.
	int _ILength;
	cout << "Nhap vao so luong phan tu: ";
	cin >> _ILength;

	for (size_t i = 0; i < _ILength; i++)
	{
		Book _BData;
		cout << "-----------Nhap vao thong tin cuon sach " << i + 1 << "-----------" << endl;
		_inputBook(_BData);

		_SNode* _PNode = _createNode(_BData);
		PUSH(s, _PNode);
	}
}

void _output(_SStack s)
{
	int ICount = 0;
	while (!EMPTY(s))
	{
		cout << "--------------Cuon Sach Thu" << ++ICount << "--------------" << endl;
		TOP(s); // Lấy ra phần tử đầu.
		POP(s); // Loại bỏ phần tử đầu.
	}
}

void POP(_SStack& s)
{
	if (!EMPTY(s))
	{
		_SNode* _Temp = s.PtrTop;
		s.PtrTop = s.PtrTop->_PNext;
		delete _Temp;
	}
}

bool EMPTY(_SStack s)
{
	return (s.PtrTop == nullptr ? true : false);
}

void TOP(_SStack s)
{
	if (!EMPTY(s))
	{
		Book b;
		/*b.ID = s.PtrTop->_IData.ID;
		b.Name = s.PtrTop->_IData.Name;
		b.Author = s.PtrTop->_IData.Author;*/
		b = s.PtrTop->_IData;
		_outputBook(b);
	}
}

