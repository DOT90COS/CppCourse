#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include <fstream>

class IFileWriter {
public:
	virtual ~IFileWriter() {}
	virtual bool writeFile(const std::string& contents) = 0;
};

class IFileReader {
public:
	virtual ~IFileReader() {}
	virtual std::string readFile() = 0;
};

class IFileOps : public IFileReader, public IFileWriter {
public:
	virtual ~IFileOps() {}
	virtual bool openFile(const std::string& filename, bool writing) = 0;
	virtual bool closeFile() = 0;

};

std::shared_ptr<IFileOps> get_file_ops();

