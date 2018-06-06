/////////////////////////////////////////////////////////////////////////////////////////////
// IDataStream.h
//
// Abstract Class Fot Input/Outputa Data Stream
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __IDATASTREAM_H__
#define __IDATASTREAM_H__

#include <stdio.h>
#include "Base/Common/PlatformTypes.h"

///////////////////////////////////////////////////////////////////////////////////////
enum SeekMode
{
    seek_set = 0,
    seek_curr = 1,
    seek_end = 2,
};

///////////////////////////////////////////////////////////////////////////////////////
class IDataStream
{
public:
    IDataStream(){};
    virtual ~IDataStream(){}

    virtual uint_t Read(void *data, uint_t size) = 0;
    virtual uint_t Write(const void *data, uint_t size) = 0;

    virtual boolt IsOpened() = 0;
    virtual boolt Seek(isize_t offset, SeekMode mode) = 0;

    virtual isize_t GetPos() = 0;
    virtual isize_t GetSize() = 0;

    virtual boolt IsEOS() = 0;
};

///////////////////////////////////////////////////////////////////////////////////////

#endif //__IDATASTREAM_H__
