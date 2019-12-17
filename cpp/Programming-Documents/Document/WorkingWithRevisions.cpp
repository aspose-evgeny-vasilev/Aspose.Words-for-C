#include "stdafx.h"
#include "examples.h"

#include <system/enumerator_adapter.h>
#include <Layout/Public/LayoutOptions.h>
#include <Layout/Public/RevisionOptions.h>
#include <Layout/Public/ShowInBalloons.h>
#include <Model/Document/Document.h>
#include <Model/Revisions/RevisionCollection.h>
#include <Model/Revisions/RevisionType.h>
#include <Model/Revisions/RevisionGroupCollection.h>
#include <Model/Revisions/RevisionGroup.h>
#include <Model/Sections/Body.h>
#include <Model/Sections/Section.h>
#include <Model/Text/ParagraphCollection.h>
#include <Model/Text/Paragraph.h>

using namespace Aspose::Words;
using namespace Aspose::Words::Layout;

namespace
{
    void AcceptRevisions(System::String const &inputDataDir, System::String const &outputDataDir)
    {
        // ExStart:AcceptAllRevisions
        System::SharedPtr<Document> doc = System::MakeObject<Document>(inputDataDir + u"Document.doc");
        // Start tracking and make some revisions.
        doc->StartTrackRevisions(u"Author");
        doc->get_FirstSection()->get_Body()->AppendParagraph(u"Hello world!");
        // Revisions will now show up as normal text in the output document.
        doc->AcceptAllRevisions();
        System::String outputPath = outputDataDir + u"WorkingWithRevisions.AcceptRevisions.doc";
        doc->Save(outputPath);
        // ExEnd:AcceptAllRevisions
        std::cout << "All revisions accepted." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    }

    void GetRevisionTypes(System::String const &inputDataDir)
    {
        // ExStart:GetRevisionTypes
        System::SharedPtr<Document> doc = System::MakeObject<Document>(inputDataDir + u"Revisions.docx");

        System::SharedPtr<ParagraphCollection> paragraphs = doc->get_FirstSection()->get_Body()->get_Paragraphs();
        for (int32_t i = 0; i < paragraphs->get_Count(); i++)
        {
            if (paragraphs->idx_get(i)->get_IsMoveFromRevision())
            {
                std::cout << "The paragraph " << i << " has been moved (deleted)." << std::endl;
            }
            if (paragraphs->idx_get(i)->get_IsMoveToRevision())
            {
                std::cout << "The paragraph " << i << " has been moved (inserted)." << std::endl;
            }
        }
        // ExEnd:GetRevisionTypes
    }

    void GetRevisionGroups(System::String const &inputDataDir)
    {
        // ExStart:GetRevisionGroups
        System::SharedPtr<Document> doc = System::MakeObject<Document>(inputDataDir + u"Revisions.docx");
        for (System::SharedPtr<RevisionGroup> group : System::IterateOver(doc->get_Revisions()->get_Groups()))
        {
            std::cout << group->get_Author().ToUtf8String() << ", :" << System::ObjectExt::Box<RevisionType>(group->get_RevisionType())->ToString().ToUtf8String() << std::endl;
            std::cout << group->get_Text().ToUtf8String() << std::endl;
        }
        // ExEnd:GetRevisionGroups
    }

    void SetShowCommentsInPDF(System::String const &inputDataDir, System::String const &outputDataDir)
    {
        // ExStart:SetShowCommentsinPDF
        System::SharedPtr<Document> doc = System::MakeObject<Document>(inputDataDir + u"Revisions.docx");

        //Do not render the comments in PDF
        doc->get_LayoutOptions()->set_ShowComments(false);
        System::String outputPath = outputDataDir + u"WorkingWithRevisions.SetShowCommentsinPDF.pdf";
        doc->Save(outputPath);
        // ExEnd:SetShowCommentsinPDF
        std::cout << "File saved at " << outputPath.ToUtf8String() << std::endl;
    }

    void SetShowInBalloons(System::String const &inputDataDir, System::String const &outputDataDir)
    {
        // ExStart:SetShowInBalloons
        System::SharedPtr<Document> doc = System::MakeObject<Document>(inputDataDir + u"Revisions.docx");

        // Renders insert and delete revisions inline, format revisions in balloons.
        doc->get_LayoutOptions()->get_RevisionOptions()->set_ShowInBalloons(ShowInBalloons::Format);

        // Renders insert revisions inline, delete and format revisions in balloons.
        //doc->get_LayoutOptions()->get_RevisionOptions()->set_ShowInBalloons(ShowInBalloons::FormatAndDelete);

        System::String outputPath = outputDataDir + u"WorkingWithRevisions.SetShowInBalloons.pdf";
        doc->Save(outputPath);
        // ExEnd:SetShowInBalloons
        std::cout << "File saved at " << outputPath.ToUtf8String() << std::endl;
    }

    void GetRevisionGroupDetails(System::String const &inputDataDir)
    {
        // ExStart:GetRevisionGroupDetails
        System::SharedPtr<Document> doc = System::MakeObject<Document>(inputDataDir + u"TestFormatDescription.docx");

        for (System::SharedPtr<Revision> revision : System::IterateOver(doc->get_Revisions()))
        {
            System::String groupText = revision->get_Group() != nullptr ? System::String(u"Revision group text: ") + revision->get_Group()->get_Text() : u"Revision has no group";

            std::cout << "Type: " << System::ObjectExt::ToString(revision->get_RevisionType()).ToUtf8String() << std::endl;
            std::cout << "Author: " << revision->get_Author().ToUtf8String() << std::endl;
            std::cout << "Date: " << revision->get_DateTime().ToString().ToUtf8String() << std::endl;
            std::cout << "Revision text: " << revision->get_ParentNode()->ToString(Aspose::Words::SaveFormat::Text).ToUtf8String() << std::endl;
            std::cout << groupText.ToUtf8String() << std::endl;
        }
        // ExEnd:GetRevisionGroupDetails
    }
}

void WorkingWithRevisions()
{
    std::cout << "WorkingWithRevisions example started." << std::endl;
    // The path to the documents directories.
    System::String inputDataDir = GetInputDataDir_WorkingWithDocument();
    System::String outputDataDir = GetOutputDataDir_WorkingWithDocument();
    AcceptRevisions(inputDataDir, outputDataDir);
    GetRevisionTypes(inputDataDir);
    GetRevisionGroups(inputDataDir);
    SetShowCommentsInPDF(inputDataDir, outputDataDir);
    SetShowInBalloons(inputDataDir, outputDataDir);
    GetRevisionGroupDetails(inputDataDir);
    std::cout << "WorkingWithRevisions example finished." << std::endl << std::endl;
}