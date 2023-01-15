all:
	g++ -o simple-dbms \
		src/main.cpp \
		src/types/sources/Type.cpp \
		src/types/sources/Integer.cpp \
		src/types/sources/Double.cpp \
		src/types/sources/Text.cpp \
		src/types/sources/Boolean.cpp \
		src/factories/sources/TypeFactory.cpp \
		src/factories/sources/CommandFactory.cpp \
		src/commands/sources/CreateTableCommand.cpp \
		src/commands/sources/Command.cpp \
		src/commands/sources/InsertIntoCommand.cpp \
		src/commands/sources/UpdateCommand.cpp \
		src/commands/sources/SelectCommand.cpp \
		src/commands/sources/CreateIndexCommand.cpp \
		src/structure/sources/Table.cpp \
		src/structure/sources/Column.cpp \
		src/helpers/sources/BinaryReader.cpp \
		src/helpers/sources/BinaryWriter.cpp \
		src/helpers/sources/Hash.cpp \
		src/services/sources/CreateTable.cpp \
		src/services/sources/InsertRow.cpp \
		src/Console.cpp \
		-lcrypto

remove-db:
	rm databases/*