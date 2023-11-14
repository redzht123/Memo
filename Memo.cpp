#include "Memo.h"

Memo::Memo(){
	this->get_file_path();
}

Memo::~Memo() {
	if (this->file_.is_open()) {
		this->file_.close();
	}
}


void Memo::get_file_path() {
	std::fstream temp_file("./file_path.txt", std::ios::in | std::ios::out);
	std::getline(temp_file, this->file_name_);
	temp_file.close();
}

void Memo::write_memo(const char* buffer){
	this->time_.get_time_str();
	this->file_name_ += this->time_.time_str_;
	this->file_name_ += ".data";
	this->file_.open(this->file_name_.c_str(), std::ios::out | std::ios::app);
	this->file_ << buffer;
}
