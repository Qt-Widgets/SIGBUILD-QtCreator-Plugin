#pragma once

#include "SigbuildGlobal.h"

#include <extensionsystem/iplugin.h>

class QIcon;
class QMenu;
class QSoundEffect;
class QSystemTrayIcon;

namespace ProjectExplorer { class Project; }

namespace Sigbuild
{

class OptionsPageMain;
class Settings;

class SigbuildPlugin : public ExtensionSystem::IPlugin
{
	Q_OBJECT

	Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "SIGBUILD.json")

public:
	SigbuildPlugin();
	~SigbuildPlugin();

	bool initialize(const QStringList & arguments, QString * errorString) override;
	void extensionsInitialized() override;
	ShutdownFlag aboutToShutdown() override;

private slots:
	void OnBuildStateChanged(ProjectExplorer::Project * pro);
	void OnBuildFinished(bool res);

	void OnSettingsChanged();

private:
	void CreateSystrayIcon();
	void DestroySystrayIcon();

	void CreateSounds();
	void DestroySounds();

	enum class BuildState;
	void SetBuildState(BuildState state);

private:
	enum class BuildState
	{
		BUILDING = 0,
		FAILED,
		OK,

		NUM
	};

	static const int NUM_BUILD_STATES = static_cast<int>(BuildState::NUM);

private:
	Settings * mSettings = nullptr;

	OptionsPageMain * mOptionsPage = nullptr;

	QMenu * mTrayMenu = nullptr;
	QSystemTrayIcon * mTrayIcon  = nullptr;

	QSoundEffect * mSoundSuccess = nullptr;
	QSoundEffect * mSoundFail = nullptr;

	quint64 mTimeBuildStart = 0;

	BuildState mBuildState;

	QIcon * mIconStates[NUM_BUILD_STATES];
};

} // namespace Sigbuild