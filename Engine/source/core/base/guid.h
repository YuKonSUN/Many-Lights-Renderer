#ifndef GUID_H_
#define GUID_H_

#include <string>
#include <Windows.h>

class Guid
{
public:
	Guid();
	~Guid() {};

	bool operator==(const Guid& other) const;
	bool operator!=(const Guid& other) const;
	
	std::string to_string() const;

private:
#ifdef _WIN32
	GUID guid;
#else

#endif 

};

#endif