/*
Classe FileMap:
Guarda os dados de aloca��o e aloca mem�ria para ler apenas um offset do arquivo.

Classe FileMapFactory:
Gera classes FileMap.
*/
classe FileMap;
classe FileMapFactory;

/*
FileMapFactory::buildMapping:
@file: caminho para o arquivo
@return: um novo FileMap contendo as informa��es do arquivo e dados na mem�ria.
Abre o arquivo, calcula o tamanho e ent�o cria um file mapping na mem�ria.
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
@offset: onde come�a os dados.
@size: tamanho dos dados a serem lidos do arquivo.
@return: um ponteiro para a mem�ria alocada para ler os dados.
NOTA: chame o FileMap::free(ptr) para limpar a mem�ria alocada.
*/
-- LPVOID FileMap::read(DWORD HiOffset, DWORD LwOffset, DWORD size) --
return MapViewOfFile(hMap, FILE_MAP_READ, HiOffset, LwOffset, size);
-------------------------------------

/*
FileMap::free;
@ptr: ponteiro alocado com a fun��o read.
@return: verdadeiro: limpou a mem�ria, falso: deu erro
Libera a mem�ria alocada em ptr
*/
-- BOOL FileMap::free(LPVOID ptr) --
return UnmapViewOfFile(ptr);
---------------------------------

/*
FileMap::Destrutor;
Fecha os handles para liberar mem�ria
*/
-- FileMap::~FileMap --
CloseHandle(hMap);
CloseHandle(hFile);
-----------------------
