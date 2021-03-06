#include "stdafx.h"
#include "examples.h"

#include <Aspose.Words.Cpp/Model/Sections/Section.h>
#include <Aspose.Words.Cpp/Model/Sections/HeaderFooterCollection.h>
#include <Aspose.Words.Cpp/Model/Importing/ImportFormatMode.h>
#include <Aspose.Words.Cpp/Model/Document/Document.h>

using namespace Aspose::Words;

void UnlinkHeadersFooters()
{
    std::cout << "UnlinkHeadersFooters example started." << std::endl;
    // ExStart:UnlinkHeadersFooters
    // The path to the documents directories.
    System::String inputDataDir = GetInputDataDir_JoiningAndAppending();
    System::String outputDataDir = GetOutputDataDir_JoiningAndAppending();

    System::SharedPtr<Document> dstDoc = System::MakeObject<Document>(inputDataDir + u"TestFile.Destination.doc");
    System::SharedPtr<Document> srcDoc = System::MakeObject<Document>(inputDataDir + u"TestFile.Source.doc");

    // Unlink the headers and footers in the source document to stop this from continuing the headers and footers
    // From the destination document.
    srcDoc->get_FirstSection()->get_HeadersFooters()->LinkToPrevious(false);

    dstDoc->AppendDocument(srcDoc, ImportFormatMode::KeepSourceFormatting);
    System::String outputPath = outputDataDir + u"UnlinkHeadersFooters.doc";
    dstDoc->Save(outputPath);
    // ExEnd:UnlinkHeadersFooters
    std::cout << "Document appended successfully with unlinked header footers." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    std::cout << "UnlinkHeadersFooters example finished." << std::endl << std::endl;
}
