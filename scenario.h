#ifndef SCENARIO_H
#define SCENARIO_H


#include "application/gmlibwrapper.h"
class Simulator;
// qt
#include <QObject>
//stl
#include <memory>

/**
class Scenario : public GMlibWrapper {
  Q_OBJECT
public:
  using GMlibWrapper::GMlibWrapper;

  void    initializeScenario() override;
  void    cleanupScenario() override;

  void    simulateReplot();

  //void render(const QString &name, const QRect &viewport, GMlib::RenderTarget &target) override;
private:
    std::shared_ptr<Simulator> _simulator;

};
**/



class Scenario : public GMlibWrapper {
  Q_OBJECT
public:
  using GMlibWrapper::GMlibWrapper;

  void    initializeScenario() override;
  void    cleanupScenario() override;

//FEM
  void    simulateReplot();

private:
  std::shared_ptr<Simulator> _simulator;
};










#endif // SCENARIO_H
