/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

#if !defined(Q_MOC_RUN)
#include <ProjectInfo.h>
#include <ScreenWidget.h>
#endif

QT_FORWARD_DECLARE_CLASS(QHBoxLayout)
QT_FORWARD_DECLARE_CLASS(QVBoxLayout)

namespace O3DE::ProjectManager
{
    QT_FORWARD_DECLARE_CLASS(FormLineEditWidget)
    QT_FORWARD_DECLARE_CLASS(FormBrowseEditWidget)

    class ProjectSettingsScreen
        : public ScreenWidget
    {
    public:
        explicit ProjectSettingsScreen(QWidget* parent = nullptr);
        ~ProjectSettingsScreen() = default;
        ProjectManagerScreen GetScreenEnum() override;

        virtual ProjectInfo GetProjectInfo();

        virtual bool Validate();

    protected slots:
        virtual bool ValidateProjectName();
        virtual bool ValidateProjectPath();

    protected:
        QString GetDefaultProjectPath();

        QHBoxLayout* m_horizontalLayout;
        QVBoxLayout* m_verticalLayout;
        FormLineEditWidget* m_projectName;
        FormBrowseEditWidget* m_projectPath;
    };

} // namespace O3DE::ProjectManager
