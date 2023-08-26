DELETE FROM `command` WHERE `name` IN ('defend');
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('defend', 0, 'Syntax: .defend \nJoin your faction in defending your city.');
