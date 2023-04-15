#pragma once
#include <ctime>
#include <string>
class Exception {
public:
	std::string error_name;
	std::string file_name;
	std::string function;
	size_t line;
	std::string time;
	Exception(const std::string& error_name, const std::string& file_name, const std::string& function, size_t line) {
		this->error_name = error_name;
		this->file_name = file_name;
		this->function = function;
		this->line = line;
		this->time = __TIME__;
	}
};
std::ostream& operator<< (std::ostream& stream, const Exception& exception) {
	stream << "Error name: " << exception.error_name << std::endl <<
		"File: " << exception.file_name << std::endl <<
		"Function: " << exception.function << std::endl <<
		"Line: " << exception.line << std::endl <<
		"Time: " << exception.time << std::endl;
	return stream;
}
class OutOfRangeException : public Exception {
public:
	OutOfRangeException(const std::string& file_name, const std::string& function, size_t line) :Exception(std::string("OutOfRange"), file_name, function, line) {}
};