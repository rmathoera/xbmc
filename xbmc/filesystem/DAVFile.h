#pragma once
/*
*      Copyright (C) 2005-2012 Team XBMC
*      http://www.xbmc.org
*
*  This Program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2, or (at your option)
*  any later version.
*
*  This Program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with XBMC; see the file COPYING.  If not, write to
*  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
*  http://www.gnu.org/copyleft/gpl.html
*
*/

#include "IFile.h"
#include "CurlFile.h"

namespace XFILE
{
  class CDAVFile : public CCurlFile
  {
  public:
    CDAVFile(void);
    virtual ~CDAVFile(void);

    virtual bool Open(const CURL& url);
    virtual bool OpenForWrite(const CURL& url, bool bOverWrite = false);
    virtual bool Exists(const CURL& url);
    virtual int Stat(const CURL& url, struct __stat64* buffer);
    virtual unsigned int Read(void* lpBuf, int64_t uiBufSize);
    virtual int Write(const void* lpBuf, int64_t uiBufSize);
    virtual bool ReadString(char *szLine, int iLineLength);
    virtual int64_t Seek(int64_t iFilePosition, int iWhence = SEEK_SET);
    virtual void Close();
    virtual int64_t GetPosition();
    virtual int64_t GetLength();
    virtual void Flush();

    /* Returns the minium size that can be read from input stream.   *
    * For example cdrom access where access could be sector based.  *
    * This will cause file system to buffer read requests, to       *
    * to meet the requirement of CFile.                             *
    * It can also be used to indicate a file system is non buffered *
    * but accepts any read size, have it return the value 1         */
    virtual int  GetChunkSize();

    virtual bool SkipNext();

    virtual bool Delete(const CURL& url);
    virtual bool Rename(const CURL& url, const CURL& urlnew);
    virtual bool SetHidden(const CURL& url, bool hidden);

    virtual int IoControl(EIoControl request, void* param);

    virtual CStdString GetContent();
  };
}