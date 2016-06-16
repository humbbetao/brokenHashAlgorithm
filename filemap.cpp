/*
Classe FileMap:
Guarda os dados de alocação e aloca memória para ler apenas um offset do arquivo.

Classe FileMapFactory:
Gera classes FileMap.
*/
classe FileMap;
classe FileMapFactory;

/*
FileMapFactory::buildMapping:
@file: caminho para o arquivo
@return: um novo FileMap contendo as informações do arquivo e dados na memória.
Abre o arquivo, calcula o tamanho e então cria um file mapping na memória.
*/
-- FileMap* FileMapFactory::buildMapping(LPCSTR* file); --
HANDLE hFile = CreateFile(file, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
if (hFile == INVALID_HANDLE_VALUE) return NULL;
DWORD HiSz, LwSz;
LwSz = GetFileSize(hFile, &HiSz);
HANDLE hMap = CreateFileMapping(hFile, NULL, PAGE_READONLY, HiSz, LwSz, NULL);
return new FileMap(hFile, HiSz, LwSz, hMap);
----------------------------------------------

/*
FileMap::read;
@offset: onde começa os dados.
@size: tamanho dos dados a serem lidos do arquivo.
@return: um ponteiro para a memória alocada para ler os dados.
NOTA: chame o FileMap::free(ptr) para limpar a memória alocada.
*/
-- LPVOID FileMap::read(DWORD HiOffset, DWORD LwOffset, DWORD size) --
return MapViewOfFile(hMap, FILE_MAP_READ, HiOffset, LwOffset, size);
-------------------------------------

/*
FileMap::free;
@ptr: ponteiro alocado com a função read.
@return: verdadeiro: limpou a memória, falso: deu erro
Libera a memória alocada em ptr
*/
-- BOOL FileMap::free(LPVOID ptr) --
return UnmapViewOfFile(ptr);
---------------------------------

/*
FileMap::Destrutor;
Fecha os handles para liberar memória
*/
-- FileMap::~FileMap --
CloseHandle(hMap);
CloseHandle(hFile);
-----------------------
