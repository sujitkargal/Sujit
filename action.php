<?php
// Connect to database
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "database_name";

$conn = new mysqli($servername, $username, $password, $dbname);

// Add task
if (isset($_POST['add_task'])) {
  $task_name = $_POST['task_name'];

  $sql = "INSERT INTO tasks (task_name) VALUES ('$task_name')";
  $conn->query($sql);
}

// Delete task
if (isset($_GET['delete_task'])) {
  $id = $_GET['delete_task'];

  $sql = "DELETE FROM tasks WHERE id=$id";
  $conn->query($sql);
}

// Mark as completed
if (isset($_GET['complete_task'])) {
  $id = $_GET['complete_task'];

  $sql = "UPDATE tasks SET completed=true WHERE id=$id";
  $conn->query($sql);
}

// Get list of tasks
$sql = "SELECT * FROM tasks";
$result = $conn->query($sql);

// Get list of completed tasks
$sql = "SELECT * FROM tasks WHERE completed=true";
$completed_result = $conn->query($sql);

// Get list of pending tasks
$sql = "SELECT * FROM tasks WHERE completed=false";
$pending_result = $conn->query($sql);

?>
