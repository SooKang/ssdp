#include <iostream>
#include <vector>
#include <allocators> // C++ ǥ�� �޸� �Ҵ��

int main()
{
	// �޸� �Ҵ� ���
	// 1. new / delete �� ���� ���
	int* p1 = new int;
	delete p1;

	int* p2 = new int;
	delete p2;

	// 2. allocator ���
	std::allocator<int> ax; 

	ax.deallocate(p, 10); 

}