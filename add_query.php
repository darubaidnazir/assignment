<?php
require_once 'conn.php';
if (isset($_POST['add'])) {
	$date = date('Y-m-d');

	if ($_POST['task'] != "" && $_POST['task_end_date'] != "") {
		$task = $_POST['task'];
		$task_end_date = $_POST['task_end_date'];

		$conn->query("INSERT INTO `task` VALUES('', '$task', '$task_end_date','Pending')");
		header('location:index.php');
	}
}