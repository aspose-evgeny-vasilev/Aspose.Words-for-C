#include "stdafx.h"
#include "examples.h"

#include <Aspose.Words.Cpp/Model/Settings/ViewType.h>
#include <Aspose.Words.Cpp/Model/Settings/ViewOptions.h>
#include <Aspose.Words.Cpp/Model/Document/Document.h>

using namespace Aspose::Words;
using namespace Aspose::Words::Settings;

void SetViewOption()
{
    std::cout << "SetViewOption example started." << std::endl;
    // ExStart:SetViewOption
    // The path to the documents directories.
    System::String inputDataDir = GetInputDataDir_WorkingWithDocument();
    System::String outputDataDir = GetOutputDataDir_WorkingWithDocument();
    // Load the template document.
    System::SharedPtr<Document> doc = System::MakeObject<Document>(inputDataDir + u"TestFile.doc");
    // Set view option.
    doc->get_ViewOptions()->set_ViewType(ViewType::PageLayout);
    doc->get_ViewOptions()->set_ZoomPercent(50);

    System::String outputPath = outputDataDir + u"SetViewOption.doc";
    // Save the finished document.
    doc->Save(outputPath);
    // ExEnd:SetViewOption
    std::cout << "View option setup successfully." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    std::cout << "SetViewOption example finished." << std::endl << std::endl;
}
