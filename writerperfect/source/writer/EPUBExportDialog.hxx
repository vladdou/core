/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_WRITERPERFECT_SOURCE_WRITER_EPUBEXPORTDIALOG_HXX
#define INCLUDED_WRITERPERFECT_SOURCE_WRITER_EPUBEXPORTDIALOG_HXX

#include <vcl/weld.hxx>

namespace comphelper
{
class SequenceAsHashMap;
}

namespace writerperfect
{
/// EPUB export options dialog.
class EPUBExportDialog : public weld::GenericDialogController
{
public:
    EPUBExportDialog(weld::Window* pParent, comphelper::SequenceAsHashMap& rFilterData,
                     css::uno::Reference<css::uno::XComponentContext> xContext,
                     css::uno::Reference<css::lang::XComponent> xDocument);
    ~EPUBExportDialog() override;

private:
    DECL_LINK(VersionSelectHdl, weld::ComboBoxText&, void);
    DECL_LINK(SplitSelectHdl, weld::ComboBoxText&, void);
    DECL_LINK(LayoutSelectHdl, weld::ComboBoxText&, void);
    DECL_LINK(CoverClickHdl, weld::Button&, void);
    DECL_LINK(MediaClickHdl, weld::Button&, void);
    DECL_LINK(OKClickHdl, weld::Button&, void);

    css::uno::Reference<css::uno::XComponentContext> m_xContext;
    comphelper::SequenceAsHashMap& m_rFilterData;
    css::uno::Reference<css::lang::XComponent> m_xSourceDocument;

    std::unique_ptr<weld::ComboBoxText> m_xVersion;
    std::unique_ptr<weld::ComboBoxText> m_xSplit;
    std::unique_ptr<weld::ComboBoxText> m_xLayout;
    std::unique_ptr<weld::Entry> m_xCoverPath;
    std::unique_ptr<weld::Button> m_xCoverButton;
    std::unique_ptr<weld::Entry> m_xMediaDir;
    std::unique_ptr<weld::Button> m_xMediaButton;
    std::unique_ptr<weld::Button> m_xOKButton;
    std::unique_ptr<weld::Entry> m_xIdentifier;
    std::unique_ptr<weld::Entry> m_xTitle;
    std::unique_ptr<weld::Entry> m_xInitialCreator;
    std::unique_ptr<weld::Entry> m_xLanguage;
    std::unique_ptr<weld::Entry> m_xDate;
};

} // namespace writerperfect

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
