
#include "OpenGEX.h"

#include <cstdio>

using namespace OpenGEX;

int main(int argc, char** argv)
{
    char* buffer = nullptr;

    // Read the file "Example.oddl" into memory.
    FILE* file = fopen("Example.ogex", "rb");
    if (file)
    {
        // Allocate space for the entire file plus one more byte for the zero
        // terminator.
        fseek(file, 0, SEEK_END);
        long size = ftell(file);
        fseek(file, 0, SEEK_SET);
        buffer = new char[size + 1];
        // Read the entire contents of the file and put a zero terminator at the
        // end.
        size_t actual = fread(buffer, 1, size, file);
        fclose(file);
        buffer[size] = 0;
    }

    if (buffer)
    {
        OpenGexDataDescription openGexDataDescription;

        // Once the file is in memory, the DataDescription::ProcessText()
        // function is called to create the structure tree and process the data.

        DataResult result = openGexDataDescription.ProcessText(buffer);
        if (result == kDataOkay)
        {
            const Structure* structure = openGexDataDescription.GetRootStructure()->GetFirstSubnode();
            while (structure)
            {
                // This loops over all top-level structures in the file.

                // Do something with the data...

                structure = structure->GetNextSubnode();
            }
        }

        delete[] buffer;
    }

    return (0);
}
