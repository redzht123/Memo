#include"Time.h"
#include"Memo.h"

int main() {
	std::string buffer;
	Memo memo;
	std::cin >> buffer;
	memo.write_memo(buffer.c_str());
	return 0;
}

