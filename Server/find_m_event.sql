SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for find_m_event
-- ----------------------------
DROP TABLE IF EXISTS `find_m_event`;
CREATE TABLE `find_m_event`  (
  `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `name` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `empire` tinyint(4) UNSIGNED NOT NULL DEFAULT 0,
  `play_time` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `try_count` int(11) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 2 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = COMPACT;

-- ----------------------------
-- Records of find_m_event
-- ----------------------------

SET FOREIGN_KEY_CHECKS = 1;
