# Copyright: 2014 UC3M
# Author: Raúl de Santos Rico
# CopyPolicy: Released under the terms of the GNU GPL v2.0.

set(appname checkCanBus)


file(GLOB conf ${CMAKE_CURRENT_SOURCE_DIR}/conf/*.ini)
file(GLOB scripts ${CMAKE_CURRENT_SOURCE_DIR}/scripts/*.template)

yarp_install(FILES ${conf} DESTINATION ${TEO-BODY_CONTEXTS_INSTALL_DIR}/${appname})
yarp_install(FILES ${scripts} DESTINATION ${TEO-BODY_APPLICATIONS_TEMPLATES_INSTALL_DIR})

