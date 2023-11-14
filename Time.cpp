#include "Time.h"

Time::Time() :buffer_size_(150) {
	this->time_str_ = new char[this->buffer_size_];
	this->time_struct_ = new tm;
}

Time::~Time() {
	delete[] this->time_str_;
	delete this->time_struct_;
}

void Time::get_time_str() {
	std::chrono::system_clock::time_point temp_time_point = std::chrono::system_clock::now();
	const std::time_t temp_time_t = std::chrono::system_clock::to_time_t(temp_time_point);
	localtime_s(this->time_struct_, &temp_time_t);
	std::strftime(this->time_str_, this->buffer_size_, "%y.%m.%d_%H-%M-%S %a ", this->time_struct_);
}

long long int Time::time_now() {
	auto time = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(time.time_since_epoch()).count();
}
