#pragma once

#include "faktum/api.hpp"



class FString;


FAK_API void FtClipboardCopy(const wchar_t* text);
FAK_API FString FtClipboardPaste();
