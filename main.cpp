#include"Time.h"
#include"Memo.h"

int main() {
	std::string buffer;
	Memo memo;
	memo.get_title();
	while (true){
		memo.get_buffer();
		memo.write_memo();
	}

	return 0;
}

