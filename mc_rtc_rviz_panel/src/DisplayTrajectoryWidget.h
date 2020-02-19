/*
 * Copyright 2016-2019 CNRS-UM LIRMM, CNRS-AIST JRL
 */

#pragma once

#include "ClientWidget.h"
#include "utils.h"

#include <mc_rtc/ros.h>

#include <visualization_msgs/MarkerArray.h>

namespace mc_rtc_rviz
{

struct DisplayTrajectoryWidget : public ClientWidget
{
  Q_OBJECT
public:
  DisplayTrajectoryWidget(const ClientWidgetParam & params, visualization_msgs::MarkerArray & markers);

  ~DisplayTrajectoryWidget() override;

  void update(const std::vector<Eigen::Vector3d> & points, const mc_rtc::gui::LineConfig & config);
  void update(const std::vector<sva::PTransformd> & points, const mc_rtc::gui::LineConfig & config);
  void update(const Eigen::Vector3d & point, const mc_rtc::gui::LineConfig & config);
  void update(const sva::PTransformd & point, const mc_rtc::gui::LineConfig & config);

private:
  visualization_msgs::MarkerArray & markers_;
  visualization_msgs::Marker path_;
  void configure(const mc_rtc::gui::LineConfig & config);
  void publish();
  bool visible_;
  bool was_visible_;
  QPushButton * button_;
private slots:
  void toggled(bool);
};

} // namespace mc_rtc_rviz
