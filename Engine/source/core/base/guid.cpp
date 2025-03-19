#include "guid.h"
#include <cassert>

Guid::Guid()
{
	assert(CoCreateGuid(&guid) == S_OK);
}

bool Guid::operator==(const Guid& other) const
{
#ifdef _WIN32
	return IsEqualGUID(guid, other.guid);
#else
	
#endif
}

bool Guid::operator!=(const Guid& other) const
{
	return !(this->guid == other.guid);
}

std::string Guid::to_string() const
{
#ifdef _WIN32
    char buffer[37]; // GUID is 36 characters + null terminator
    snprintf(buffer, sizeof(buffer),
        "%08x-%04x-%04x-%04x-%012llx",
        guid.Data1, guid.Data2, guid.Data3,
        (guid.Data4[0] << 8) | guid.Data4[1],
        (uint64_t(guid.Data4[2]) << 40) |
        (uint64_t(guid.Data4[3]) << 32) |
        (uint64_t(guid.Data4[4]) << 24) |
        (uint64_t(guid.Data4[5]) << 16) |
        (uint64_t(guid.Data4[6]) << 8) |
        uint64_t(guid.Data4[7]));
    return std::string(buffer);
#else
    
#endif
}
