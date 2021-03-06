#include "stdafx.h"
#include "examples.h"

#include <Aspose.Words.Cpp/Model/Document/Document.h>
#include <Aspose.Words.Cpp/Model/Saving/PdfFontEmbeddingMode.h>
#include <Aspose.Words.Cpp/Model/Saving/PdfSaveOptions.h>

using namespace Aspose::Words;
using namespace Aspose::Words::Saving;

namespace
{
    void SkipEmbeddedArialAndTimesRomanFonts(System::SharedPtr<Document> doc, System::String const &outputDataDir)
    {
        // ExStart:SkipEmbeddedArialAndTimesRomanFonts
        // To subset fonts in the output PDF document, simply create new PdfSaveOptions and set EmbedFullFonts to false.
        // To disable embedding standard windows font use the PdfSaveOptions and set the EmbedStandardWindowsFonts property to false.
        System::SharedPtr<PdfSaveOptions> options = System::MakeObject<PdfSaveOptions>();
        options->set_FontEmbeddingMode(PdfFontEmbeddingMode::EmbedAll);

        System::String outputPath = outputDataDir + u"EmbeddingWindowsStandardFonts.SkipEmbeddedArialAndTimesRomanFonts.pdf";
        // The output PDF will be saved without embedding standard windows fonts.
        doc->Save(outputPath);
        // ExEnd:SkipEmbeddedArialAndTimesRomanFonts
        std::cout << "Embedded arial and times new roman fonts are skipped successfully." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    }
}

void EmbeddingWindowsStandardFonts()
{
    std::cout << "EmbeddingWindowsStandardFonts example started." << std::endl;
    // ExStart:AvoidEmbeddingCoreFonts
    // The path to the documents directories.
    System::String inputDataDir = GetInputDataDir_RenderingAndPrinting();
    System::String outputDataDir = GetOutputDataDir_RenderingAndPrinting();

    System::SharedPtr<Document> doc = System::MakeObject<Document>(inputDataDir + u"Rendering.doc");

    // To disable embedding of core fonts and subsuite PDF type 1 fonts set UseCoreFonts to true.
    System::SharedPtr<PdfSaveOptions> options = System::MakeObject<PdfSaveOptions>();
    options->set_UseCoreFonts(true);

    System::String outputPath = outputDataDir + u"EmbeddingWindowsStandardFonts.pdf";
    // The output PDF will not be embedded with core fonts such as Arial, Times New Roman etc.
    doc->Save(outputPath);
    // ExEnd:AvoidEmbeddingCoreFonts
    std::cout << "Avoid embedded core fonts setup successfully." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    SkipEmbeddedArialAndTimesRomanFonts(doc, outputDataDir);
    std::cout << "EmbeddingWindowsStandardFonts example finished." << std::endl << std::endl;
}